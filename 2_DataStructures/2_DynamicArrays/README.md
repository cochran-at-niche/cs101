# Dynamic Arrays

[Class 1 Lecture Slides](https://docs.google.com/presentation/d/1ce7xoJFkOzaeHVtLlKMjTqQRrouImNf07GBbZ7iphyQ/edit?usp=sharing)

The goal of this assignment is to gain an understanding of how memory is
allocated, the limitations that imposes on us, and how we can cope with it by
creating data structures that abstract the details of manual memory management
away. By understanding the kinds of trade-offs we have to deal with when
thinking about memory layout and allocation, we set the stage for understanding
more sophisticated data types, such as linked lists and binary trees.

This also serves as a (hopefully) gentle introduction to the C programming
language, which we will be our main programming language for this data
structures course going forward.

## Assignment

Your task is to implement a [dynamic
array](https://en.wikipedia.org/wiki/Dynamic_array). I have provided the
skeleton in `dynamic_array.c`. A standard array in C has a fixed size which is
allocated when it is created, which limits the number of items that can be
stored in it. A dynamic array is an array data structure capable of
automatically resizing itself to accommodate more items. In order to do so, it
must keep track of its size (the current number of items in the array) as well
as its capacity (the maximum number of items that can be stored in the array,
given the amount of memory current allocated to it). When the size of the array
reaches the capacity, the array needs to be resized to hold more items. This is
typically done by allocating memory for a new array twice as large, copying all
the items over to it, and freeing the memory allocated for the original array.

Our dynamic array has methods for adding items, removing items, and
checking whether an item exists in the array. In other words, it implements the
"Bag" ADT from the previous lesson. Just like in the previous lesson, the items
we are storing are just integers.

### Prerequisites

1. [Install docker](https://docs.docker.com/install/)
2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
3. Clone (or fork and clone) this repo: `git clone https://github.com/cochran-at-niche/cs101`
4. Make sure your local copy of the repo is up-to-date: `git pull`

### Instructions

1. Navigate to this directory: `cd cs101/2_DataStructures/2_DynamicArrays`
2. Run `make test` (if you have gcc installed and would rather build/run the
   tests locally, run `make test.out && ./test.out` instead). *You should see a
   bunch of failing tests*.
3. Open the `dynamic_array.c` file. Implement the necessary code for each of the
   `TODO` comments.
4. Repeat steps 2-3 until all tests are passing.

Note: If you are curious about the tests themselves, they are in `test.c`.

## Further Reading

* Read about how Go slices are implemented (spoiler: they are dynamic arrays):
  https://blog.golang.org/go-slices-usage-and-internals
* Run this program to see how the length and capacity of a Go slice change as
  items are added to it (this should look very familiar!):
  https://play.golang.org/p/JCFJGVJh0Gv
