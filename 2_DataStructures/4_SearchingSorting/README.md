# Searching and Sorting

[Class 4 Lecture Slides](https://docs.google.com/presentation/d/1INd__JkD1sxe2vVvAiAZw068FkK4p2O7HPjcgFd_NHQ/edit?usp=sharing)

In all of the data structures we've built so far, the `Contains` method
performed a [linear search](https://en.wikipedia.org/wiki/Linear_search) with a
big O time complexity of O(n). It is possible to do better by utilizing [binary
search](https://en.wikipedia.org/wiki/Binary_search_algorithm) (which has a time
complexity of O(log n). However, binary search has a prerequisite: the array
must already be sorted.

How can we efficiently sort an array, and what is the big O time complexity of
doing so?

## Assignment

Your task is to implement an efficient sorting algorithm. By efficient, I mean
that it has a best-case/average-case time complexity of O(n log n). I recommend
one of the following:

* [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
* [Quick sort](https://en.wikipedia.org/wiki/Quicksort)
* [Heap sort](https://en.wikipedia.org/wiki/Heapsort)

This assignment begins with the dynamic array that we implemented in lesson 2.
However, it has two additional methods: `dyn_arr_insertion_sort`, which I have
already implemented for you, and `dyn_arr_sort`, which you must implement
yourself with one of the O(n log n) sorting algorithms mentioned above.

After you are done and your implementation is passing the tests, run `make
compare` to see how your algorithm compares with insertion sort on arrays of
different sizes!

### Prerequisites

1. [Install docker](https://docs.docker.com/install/)
2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
3. Clone (or fork and clone) this repo: `git clone https://github.com/cochran-at-niche/cs101`
4. Make sure your local copy of the repo is up-to-date: `git pull`

### Instructions

1. Navigate to this directory: `cd cs101/2_DataStructures/4_SearchingSorting`
2. Run `make test` (if you have gcc installed and would rather build/run the
   tests locally, run `make test.out && ./test.out` instead). *You should see a
   bunch of failing tests*.
3. Open the `dynamic_array.c` file. Implement the necessary code for each of the
   `TODO` comments.
4. Repeat steps 2-3 until all tests are passing.
5. Run `make compare` to see how your implementation compares to insertion sort
   on arrays of different sizes!

Note: If you are curious about the tests themselves, they are in `test.c`.
