# The Bag

The high-level goal of this assignment is to get familiar with the ideas of
[abstract data types](https://en.wikipedia.org/wiki/Abstract_data_type) (ADTs)
and [data structures](https://en.wikipedia.org/wiki/Data_structure). Don't worry
too much about those concepts now, though. Just try to complete the assignment
to the best of your ability. We will discuss it later.

This also serves as a (hopefully) gentle introduction to the Go programming
language. Don't worry about understanding the entirety of the language now. Just
try to figure out how to solve the problem at hand. [Go by
Example](https://gobyexample.com/) is a very good reference.

## Instructions

Your task is to implement a "bag" abstract data type, which I have provided the
skeleton for (see `bag.go`). The bag is a simple abstract data type with methods
for adding items, removing items, and checking whether an item exists in the
    bag. In our case, the items are just simple integers.

1. [Install Go 1.13](https://golang.org/doc/install), if you haven't already.
2. Clone or fork this repo. For example: `git clone https://github.com/cochran-at-niche/cs101`
3. Navigate to this directory: `cd cs101/2_DataStructures/1_TheBag`
4. Run `go test`. *You should see a bunch of failing tests*.
5. Open the `bag.go` file. Implement the necessary code for each of the `TODO` comments.
6. Repeat steps 4-5 until all tests are passing.

Note: If you are curious about the tests themselves, they are in `bag_test.go`.

Don't overthink this! Just do whatever comes to mind, and try to get the tests
to pass. There is not a single "right" answer. Feel free to ask me for advice if
you get stuck or need help!

### Bonus Points

Implement the bag ADT using only [arrays](https://gobyexample.com/arrays) - no
[slices](https://gobyexample.com/slices), [maps](https://gobyexample.com/maps),
or other data structures! Your bag should be able to grow indefinitely as more
items are added (i.e. there should not be a size limit).
