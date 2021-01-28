package main

import (
	"bufio"
	"context"
	"fmt"
	"os"
	"runtime"
	"sync"
	"time"
)

func main() {
	goroutines()
	//waitGroups()
	//channels()
	//channelRange()
	//pingPong()
	//asyncAwait()
	//generator()
	//fanIn()
	//fanOut()
	//selectStatement()
	//selectDefault()
	//selectSend()
	//cancellation()
	//contextCancellation()
	//timeout()
	//contextTimeout()
}

// Goroutines are lightweight threads. This means that they run *concurrently*.
// Furthermore, they can run in *parallel* depending on the values of
// GOMAXPROCS (which defaults to the # of cores available on your machine).
func goroutines() {
	fmt.Printf("GOMAXPROCS: %d\n", runtime.GOMAXPROCS(0))

	for i := 0; i < 10; i++ {
		fmt.Printf("Spawning goroutine #%d\n", i)

		// Spawn a new goroutine
		// Question: what happens if "go" keyword is omitted?
		// Question: what order will the goroutines finish in?
		go func(i int) {
			// Simulate a long-running task
			time.Sleep(500 * time.Millisecond)
			fmt.Printf("Goroutine #%d finished\n", i)
		}(i)
	}
	fmt.Println("Finished loop")

	// Question: what happens if we don't sleep here?
	time.Sleep(time.Second)
	fmt.Println("Done")
}

// Waitgroups are old-school synchronization mechanisms based on
// mutexes/semaphores. They're available via the sync package in the standard
// library. They're not always the right answer, but they're the best answer
// when you want to wait for a group of goroutines to finish.
func waitGroups() {
	var wg sync.WaitGroup
	for i := 0; i < 10; i++ {
		fmt.Printf("Spawning goroutine #%d\n", i)

		// Increment the wait group for each goroutine spawned
		// Question: What would happen if we put this inside of the goroutine
		// function below, instead of outside?
		wg.Add(1)

		go func(i int) {
			// Decrement the wait group when the goroutine finishes
			defer wg.Done()

			// Simulate a long-running task
			time.Sleep(500 * time.Millisecond)
			fmt.Printf("Goroutine #%d finished\n", i)
		}(i)
	}
	fmt.Println("Finished loop")

	// Wait for all goroutines to finish
	// Question: What if we needed to get some kind of result back from each of
	// the goroutines?
	wg.Wait()
	fmt.Println("Done")
}

// Channels are a more advanced synchronization mechanicsm. They are primitives
// (i.e. they are built into the language), and make it possible to communicate
// between goroutines.  They can be thought of as a thread-safe queue with
// special synchronization behavior:
//   - A send on a full channel blocks
//   - A send on a nil channel blocks
//   - A send on a closed channel panics
//   - A read from an empty channel blocks
//   - A read from a nil channel blocks
//   - A read from a closed channel immediately returns the default value
func channels() {
	// Channels can be initialized with a buffer size (i.e. 10). If the buffer
	// size is omitted, the channel is unbuffered
	channel := make(chan int, 3)

	fmt.Println("Sending on channel: 1")
	channel <- 1

	fmt.Println("Sending on channel: 2")
	channel <- 2

	fmt.Println("Sending on channel: 3")
	channel <- 3

	// Question: What would happen if the channel was unbuffered?
	// What if the buffer size was 2 instead of 3?
	fmt.Printf("Read from channel: %d\n", <-channel)
	fmt.Printf("Read from channel: %d\n", <-channel)
	fmt.Printf("Read from channel: %d\n", <-channel)
}

// You can range over a channel. The for loop exits when the channel is closed
// (after all values are drained from the channel).
func channelRange() {
	// Channels can be initialized with a buffer size (i.e. 10). If the buffer
	// size is omitted, the channel is unbuffered
	channel := make(chan int, 3)

	fmt.Println("Sending on channel: 1")
	channel <- 1

	fmt.Println("Sending on channel: 2")
	channel <- 2

	fmt.Println("Sending on channel: 3")
	channel <- 3

	// Close the channel after all results have been sent on it
	// Question: what would happen if we didn't close the channel?
	close(channel)

	for result := range channel {
		fmt.Printf("Read from channel: %d\n", result)
	}
}

// Channels are not really intended to be used in a single goroutine. Let's
// take a look at how they can be used to communicate between goroutines.  This
// also demonstrates that channels are bi-directional by default.
func pingPong() {
	channel := make(chan int)
	go func() {
		for {
			<-channel
			fmt.Println("Ping")
			time.Sleep(100 * time.Millisecond)
			channel <- 1
		}
	}()

	go func() {
		for {
			<-channel
			fmt.Println("Pong")
			time.Sleep(100 * time.Millisecond)
			channel <- 1
		}
	}()

	// Initial serve
	fmt.Println("Serve")
	channel <- 1

	time.Sleep(1 * time.Second)
}

// Channels can act like async/await
func asyncAwait() {
	// This function returns a directional channel. Think of the function as
	// an async function (i.e. a function whose result must be awaited), and
	// the channel as a future.
	future := func() <-chan string {
		c := make(chan string)
		fmt.Println("Starting long-running task")
		go func() {
			// Simulate a long-running task
			time.Sleep(100 * time.Millisecond)

			// Send the result on the channel
			fmt.Println("Sending result on channel")
			c <- "result"
		}()

		// Return the channel (empty as of right now), which acts like a future
		return c
	}()

	// Wait on the result of the channel (think of <- as an "await" call)
	fmt.Printf("Waiting to read from channel\n")
	result := <-future

	fmt.Printf("Result read from channel: %s\n", result)
}

// Channels can act like generators
func generator() {
	start := time.Now()

	// This function returns a channel. Think of the channel as an iterator and
	// the function as a generator that yields values to the caller via the
	// iterator
	generator := func() <-chan string {
		c := make(chan string)
		fmt.Println("Starting generator")
		go func() {
			for i := 0; i < 10; i++ {
				// Simulate a long-running task
				time.Sleep(100 * time.Millisecond)

				// Send the result on the channel
				// (think of this like a "yield" call)
				fmt.Printf("Sending result #%d on channel\n", i)
				c <- fmt.Sprintf("result #%d", i)
			}

			// Close the channel when we're done sending values
			// Question: What if we didn't close the channel?
			close(c)
		}()

		// Return the channel (empty as of right now), which acts like a generator
		return c
	}()

	// Wait on the result of the channel (think of <- as an "await" call).
	// The for loop executes until the channel is closed.
	fmt.Printf("Beginning to read from channel\n")
	for result := range generator {
		fmt.Printf("Result read from channel: %s\n", result)
	}
	fmt.Printf("Elapsed: %s\n", time.Since(start))
}

// One of the "Go Proverbs" is: "Don't communicate by sharing memory, share
// memory by communicating". This example is similar to the waitGroup example
// above, except now we're able to send the results back to the main goroutine
// via a channel.
func fanIn() {
	start := time.Now()

	// This function returns a channel. Think of the channel as an iterator and
	// the function as a generator that yields values to the caller via the
	// iterator
	channel := func() <-chan string {
		c := make(chan string)

		var wg sync.WaitGroup
		for i := 0; i < 10; i++ {
			fmt.Printf("Spawning goroutine #%d\n", i)
			wg.Add(1)
			go func(i int) {
				defer wg.Done()
				// Simulate a long-running task
				time.Sleep(100 * time.Millisecond)

				// Send the result on the channel
				// (think of this like a "yield" call)
				fmt.Printf("Sending result #%d on channel\n", i)
				c <- fmt.Sprintf("result #%d", i)
			}(i)
		}

		// Close the channel after all goroutines have finished sending their
		// results
		go func() {
			wg.Wait()
			close(c)
		}()

		return c
	}()

	// Wait on the result of the channel (think of <- as an "await" call).
	// The for loop executes until the channel is closed.
	fmt.Printf("Beginning to read from channel\n")
	for result := range channel {
		fmt.Printf("Result read from channel: %s\n", result)
	}
	fmt.Printf("Elapsed: %s\n", time.Since(start))
}

// This example is the opposite of the fanIn example. Rather than spawning a
// bunch of goroutines that do work, and having the main goroutine read their
// results off a channel, we have the main goroutine send onto the channel, and
// a pool of worker goroutines read from the channel. You'll notice that work
// is distributed relatively fairly amoung the goroutines. This pattern is
// often used when you need to distribute tasks amoung a pool of "workers".
// This pattern can be combined with the fanIn pattern to collect the results
// from the workers back in the main goroutine.
func fanOut() {
	var wg sync.WaitGroup
	channel := make(chan int)
	for i := 0; i < 5; i++ {
		fmt.Printf("Spawning goroutine #%d\n", i)
		wg.Add(1)
		go func(i int) {
			defer wg.Done()

			// Read results from the channel
			for result := range channel {
				fmt.Printf("Goroutine #%d read: %d\n", i, result)
			}
			fmt.Printf("Goroutine #%d finished\n", i)
		}(i)
	}
	for i := 0; i < 10; i++ {
		fmt.Sprintf("Sending %d on channel\n", i)
		channel <- i
	}

	fmt.Println("Closing channel")
	close(channel)

	fmt.Println("Waiting for goroutines to finish")
	wg.Wait()

	fmt.Println("Done")
}

// Select statements allow you to wait on results from more than one channel.
// The first result available causes the corresponding case to be evaluated.
// Superficially, select statements look a lot like switch statements, but
// semantically, they are very different.
func selectStatement() {
	// time.After returns a channel, and <- awaits the result
	// (see the asyncAwait example)
	select {
	case <-time.After(100 * time.Millisecond):
		// This case always wins
		fmt.Println("Case 1")
	case <-time.After(1 * time.Second):
		fmt.Println("Case 2")
	}
}

// Select statements can have a default clause, which is evaluated immediately
// if all of the channel operations in the other cases are blocked.
func selectDefault() {
	// time.After returns a channel, and <- awaits the result
	// (see the asyncAwait example)
	select {
	case <-time.After(100 * time.Millisecond):
		fmt.Println("Case 1")
	case <-time.After(1 * time.Second):
		fmt.Println("Case 2")
	default:
		// The default case always wins
		fmt.Println("Default")
	}
}

// You can also send to a channel in a select statement. If multiple cases can
// execute, one is randomly selected. If all channels operations are blocked,
// the default case executes
func selectSend() {
	// time.After returns a channel, and <- awaits the result
	// (see the asyncAwait example)
	chan1 := make(chan int, 5)
	chan2 := make(chan int, 5)
	for i := 0; i < 11; i++ {
		select {
		case chan1 <- i:
			fmt.Printf("Send %d on channel #1\n", i)
		case chan2 <- i:
			fmt.Printf("Send %d on channel #2\n", i)
		default:
			fmt.Println("All channels are full!")
			return
		}
	}
}

// Cancellation is a more realistic example of how select statements can be
// useful. This example is similar to our ping pong example, except that now we
// are able to cancel the goroutines.
func cancellation() {
	channel := make(chan int)
	done := make(chan struct{})
	var wg sync.WaitGroup

	wg.Add(1)
	go func() {
		defer wg.Done()

		for {
			select {
			case <-channel:
			case <-done:
				fmt.Println("Goroutine #1 stopping")
				return
			}

			fmt.Println("Ping")
			time.Sleep(100 * time.Millisecond)

			select {
			case channel <- 1:
			case <-done:
				fmt.Println("Goroutine #1 stopping")
				return
			}
		}
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()

		for {
			select {
			case <-channel:
			case <-done:
				fmt.Println("Goroutine #2 stopping")
				return
			}

			fmt.Println("Pong")
			time.Sleep(100 * time.Millisecond)

			select {
			case channel <- 1:
			case <-done:
				fmt.Println("Goroutine #2 stopping")
				return
			}
		}
	}()

	// Initial serve
	fmt.Println("Serve")
	channel <- 1

	// Wait for user input, then cancel the goroutines
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Println("Closing done channel")
	close(done)

	fmt.Println("Waiting for goroutines to finish")
	wg.Wait()

	fmt.Println("Done")
}

func contextCancellation() {
	channel := make(chan int)
	ctx, cancel := context.WithCancel(context.Background())
	var wg sync.WaitGroup

	wg.Add(1)
	go func() {
		defer wg.Done()

		for {
			select {
			case <-channel:
			case <-ctx.Done():
				fmt.Println("Goroutine #1 stopping")
				return
			}

			fmt.Println("Ping")
			time.Sleep(100 * time.Millisecond)

			select {
			case channel <- 1:
			case <-ctx.Done():
				fmt.Println("Goroutine #1 stopping")
				return
			}
		}
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()

		for {
			select {
			case <-channel:
			case <-ctx.Done():
				fmt.Println("Goroutine #2 stopping")
				return
			}

			fmt.Println("Pong")
			time.Sleep(100 * time.Millisecond)

			select {
			case channel <- 1:
			case <-ctx.Done():
				fmt.Println("Goroutine #2 stopping")
				return
			}
		}
	}()

	// Initial serve
	fmt.Println("Serve")
	channel <- 1

	// Wait for user input, then cancel the goroutines
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Println("Cancelling context")
	cancel()

	fmt.Println("Waiting for goroutines to finish")
	wg.Wait()

	fmt.Println("Done")
}

// Setting a timeout is a more realistic example of how select statements can be useful
func timeout() {
	start := time.Now()

	// This is just the generator from the generator example
	generator := func() <-chan string {
		c := make(chan string)
		fmt.Println("Starting generator")
		go func() {
			for i := 0; i < 10; i++ {
				time.Sleep(100 * time.Millisecond)
				fmt.Printf("Sending result #%d on channel\n", i)
				c <- fmt.Sprintf("result #%d", i)
			}
			close(c)
		}()
		return c
	}()

	// We want to time out after 500 milliseconds
	timeoutChan := time.After(500 * time.Millisecond)

	// Read from the generator, but quit if the timeout is reached
	// Question: what would happen if the timeout was longer than it took to
	// generate all of the results?
	fmt.Printf("Beginning to read from channel\n")
	for {
		select {
		case result := <-generator:
			fmt.Printf("Result read from channel: %s\n", result)
		case <-timeoutChan:
			fmt.Printf("Timeout!\n")
			fmt.Printf("Elapsed: %s\n", time.Since(start))
			return
		}
	}
}

// The context package is a more idiomatic way to set timeouts, but it's very
// similar under the hood
func contextTimeout() {
	start := time.Now()

	// This is just the generator from the generator example
	generator := func() <-chan string {
		c := make(chan string)
		fmt.Println("Starting generator")
		go func() {
			for i := 0; i < 10; i++ {
				time.Sleep(100 * time.Millisecond)
				fmt.Printf("Sending result #%d on channel\n", i)
				c <- fmt.Sprintf("result #%d", i)
			}
			close(c)
		}()
		return c
	}()

	// We want to time out after 500 milliseconds
	context, _ := context.WithTimeout(context.Background(), 500*time.Millisecond)

	// Read from the generator, but quit if the timeout is reached
	// Question: what would happen if the timeout was longer than it took to
	// generate all of the results?
	fmt.Printf("Beginning to read from channel\n")
	for {
		select {
		case result := <-generator:
			fmt.Printf("Result read from channel: %s\n", result)
		case <-context.Done():
			fmt.Printf("Context timeout!\n")
			fmt.Printf("Elapsed: %s\n", time.Since(start))
			return
		}
	}
}
