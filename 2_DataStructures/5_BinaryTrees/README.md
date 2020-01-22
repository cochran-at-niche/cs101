# Binary Trees

[Class 5 Lecture Slides](https://docs.google.com/presentation/d/1sd8uJCkBc8nxIX5PARVIcDBou5Vq5eVIiaxUUMwb7Pw/edit#slide=id.g7687a35c2d_0_136)

Previously, we learned that binary search on a sorted array takes O(log n) time,
which is much better than linear search (O(n)). However, sorting an array takes
O(n log n) time, which is worse than linear search. Hence, it doesn't
necessarily make sense to sort an array just to search through it once.

We therefore might decide to keep our array sorted. Finding the position to
insert a new item could be done in O(log n) time, since the array is sorted -
however, as discussed in lesson #2 when we talked about dynamic arrays, we would
still have to shift items to make room for the new item, which would take O(n)
time. A similar problem presents itself when we consider the removal operation.

We previously eliminated the need to shift items by implementing a linked list
instead of a dynamic array. With a linked list, once we knew where we want to
insert/remove an item from the list, we can do it in O(1) time, just by swapping
some pointers. However, we can't do binary search on a linked list, because it
doesn't support random access/indexing. Is there a way we could combine the
O(log n) search time of a sorted array with the O(1) insertion/removal time of a
linked list?

## Assignment

Your task is to implement a basic [binary search
tree](https://en.wikipedia.org/wiki/Binary_search_tree). Your binary search tree
will have the same "Bag ADT" methods that we've been working with all along:
`add`, `remove`, and `contains`.

For bonus points, implement a self-balancing tree. I would recommend one of the
following:
  * [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree)
  * [Red Black Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
  * [B-Tree](https://en.wikipedia.org/wiki/B-tree)

### Prerequisites

1. [Install docker](https://docs.docker.com/install/)
2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
3. Clone (or fork and clone) this repo: `git clone https://github.com/cochran-at-niche/cs101`
4. Make sure your local copy of the repo is up-to-date: `git pull`

### Instructions

1. Navigate to this directory: `cd cs101/2_DataStructures/5_BinaryTrees`
2. Run `make test` (if you have gcc installed and would rather build/run the
   tests locally, run `make test.out && ./test.out` instead). *You should see a
   bunch of failing tests*.
3. Open the `binary_tree.c` file. Implement the necessary code for each of the
   `TODO` comments.
4. Repeat steps 2-3 until all tests are passing.

Note: If you are curious about the tests themselves, they are in `test.c`.
