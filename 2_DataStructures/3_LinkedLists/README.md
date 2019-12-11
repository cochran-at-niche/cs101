# Linked Lists

[Class 2 Lecture Slides](https://docs.google.com/presentation/d/1Dx6PoMjyNe96TGa-06eUExt5f3-goE7GnRqZvv0TcS4/edit?usp=sharing)

[Class 3 Lecture Slides](https://docs.google.com/presentation/d/10PrJNRxBrqLBX-KCDropbsOVwkFdWX5t94RIJjmcyHQ/edit?usp=sharing)

In the previous assignment, we implemented a dynamic array that automatically
resized when it reached capacity. The resize operation involved allocating
memory for a new, larger array, and copying the entire array over, which is
O(n), where n is the number of items in the array. Furthermore, the removal
operation was O(n), due to the need to first find the item in the array, and
then to shift all of the items after it back one position. Can we do better?
What would the trade-offs be?

## Assignment

A [linked list](https://en.wikipedia.org/wiki/Linked_list) is a data structure
which, unlike an array, does not store items contiguously in memory. Rather,
items are spread out in memory, and each item maintains a pointer to the next
item in the list. This allows us to allocate memory incrementally, when it's
needed, rather than allocating it up front. The benefit is that we no longer
have to resize the underlying array when it reaches capacity - in fact, the list
does not have an underlying array, and therefore does not have a capacity
(besides the available memory on your computer). Furthermore, it is possible to
remove an item from the middle of a linked list without having to shift all of
the items after it, by simply adjusting the pointers of the items before and
after it. The downside to a linked list, compared to an array, is that each item
in our list now requires additional memory to hold the pointer to the next item
in the list.

Your task is to implement a variant of a linked list known as a circular
[doubly-linked list](https://en.wikipedia.org/wiki/Doubly_linked_list). A
doubly-linked list is similar to a linked list, except that, in addition to a
pointer to the next item in the list, each item also has a pointer to the
previous item. This allows for both forward and backward traversal through the
list. Furthermore, our list is _circular_ because it maintains a sentinel node
(a permanent node at the base of the list that holds no actual data) which acts
as both the start and end of the list. In other words, the sentinel's "next"
pointer points to the first item in the list, and its "previous" pointer points
to the last item in the list (conversely, the first item's "previous" pointer
points back to the sentinel node, as does the last item's "next" pointer). This
makes it easy to access both the start and end of the list. However, accessing
items in the middle of the list is no longer easy, as it requires traversal
starting from the front or back.

As in previous lessons, our doubly-linked list will have methods from the Bag
ADT. However, instead of a generic "add" method, it will have more specific
methods for adding/removing items from the start or end of the list. These
methods belong to the [Doubled-Ended Queue ADT](https://en.wikipedia.org/wiki/Double-ended_queue),
which can be thought of as a combination of a
[Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) and a
[Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)).

### Prerequisites

1. [Install docker](https://docs.docker.com/install/)
2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
3. Clone (or fork and clone) this repo: `git clone https://github.com/cochran-at-niche/cs101`
4. Make sure your local copy of the repo is up-to-date: `git pull`

### Instructions

1. Navigate to this directory: `cd cs101/2_DataStructures/3_LinkedLists`
2. Run `make test` (if you have gcc installed and would rather build/run the
   tests locally, run `make test.out && ./test.out` instead). *You should see a
   bunch of failing tests*.
3. Open the `linked_list.c` file. Implement the necessary code for each of the
   `TODO` comments.
4. Repeat steps 2-3 until all tests are passing.

Note: If you are curious about the tests themselves, they are in `test.c`.

## Further Reading

* Have a look at [container/list](https://golang.org/pkg/container/list/) from
  the Go standard library. It is [implemented](https://golang.org/src/container/list/list.go)
  as a circular doubly-linked list with a sentinel node, nearly identical to
  the one you created for this assignment.
