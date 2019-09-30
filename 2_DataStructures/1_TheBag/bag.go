package bag

// Bag is a simple abstract data type (ADT) for storing items. It has methods
// for adding and removing items, checking if a given item exists in the bag,
// and getting the number of items stored in the bag.
type Bag struct {
	// TODO: Add fields here for storing items. You can use any data structure
	// you want (there is no "right" answer). The fields you add here will be
	// accessible in the functions below as "b.field", where "field" is the
	// name of the field.
}

// NewBag is used to create an instance of a Bag.
func NewBag() *Bag {
	return &Bag{
		// TODO: If necessary, initialize fields here.
	}
}

// Add inserts an item into the bag. The bag should accept and store duplicate
// items (i.e. it is not a set).
func (b *Bag) Add(i int) {
	// TODO: Implement the Add method.

	return
}

// Remove takes an item out of the bag, if it exists. If there are duplicate
// items in the bag, it should only remove one of them. If the item does not
// exist in the bag, it should silently do nothing.
func (b *Bag) Remove(i int) {
	// TODO: Implement the Remove method.

	return
}

// Contains returns true if the given item exists in the bag, and false
// otherwise.
func (b *Bag) Contains(i int) bool {
	// TODO: Implement the Contains method.

	return false
}

// Size returns the number of items in the bag.
func (b *Bag) Size() int {
	// TODO: Implement the size method.

	return 0
}
