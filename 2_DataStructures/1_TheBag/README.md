# The Bag

The high-level goal of this assignment is to get familiar with the ideas of
[abstract data types](https://en.wikipedia.org/wiki/Abstract_data_type) (ADTs)
and [data structures](https://en.wikipedia.org/wiki/Data_structure). Don't worry
too much about those concepts now - just try to complete the assignment to the
best of your ability. We will discuss it later.

This also serves as a (hopefully) gentle introduction to the Go programming
language. Go is a high-level language with a lot of similarities to lower-level
languages, especially C. This course will mostly be in C going forward, but it
will be useful to compare/contrast the two languages as we progress through the
course. Don't worry about understanding the entirety of the language now.  Just
try to figure out how to solve the problem at hand. [Go by
Example](https://gobyexample.com/) is an excellent resource.

## Assignment

Your task is to implement a [bag](https://en.wikipedia.org/wiki/Set_(abstract_data_type)#Multiset)
abstract data type, which I have provided the skeleton for (`bag.go`). The bag
is a simple abstract data type with methods for adding items, removing items,
and checking whether an item exists in the bag. In our case, the items are just
integers.

### Prerequisites

1. [Install docker](https://docs.docker.com/install/)
2. [Install Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
3. Clone (or fork and clone) this repo: `git clone https://github.com/cochran-at-niche/cs101`
4. Make sure your local copy of the repo is up-to-date: `git pull`

### Instructions

1. Navigate to the project directory: `cd cs101/2_DataStructures/1_TheBag`
2. Run `make test` (if you have `go` installed and would rather run the tests
   locally, run `go test` instead). *You should see a bunch of failing tests*.
3. Open the `bag.go` file. Implement the necessary code for each of the `TODO` comments.
4. Repeat steps 2-3 until all tests are passing.

Don't overthink it! Just do whatever comes to mind, and try to get the tests to
pass. There is not a single "right" answer. Definitely feel free to ask for
advice if you get stuck or need help!

Note: If you are curious about the tests themselves, they are in `bag_test.go`.
