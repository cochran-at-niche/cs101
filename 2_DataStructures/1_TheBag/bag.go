package bag

// Bag is a simple abstract data type (ADT) for storing items. It has methods
// for adding and removing items, checking if a given item exists in the bag,
// and getting the number of items stored in the bag.
type Bag struct {
	items []int
}

// NewBag is used to create an instance of a Bag.
func NewBag() *Bag {
	return &Bag{}
}

// Add inserts an item into the bag. The bag should accept and store duplicate
// items (i.e. it is not a set).
func (b *Bag) Add(i int) {
	b.items = append(b.items, i)
	return
}

// Remove takes an item out of the bag, if it exists. If there are duplicate
// items in the bag, it should only remove one of them. If the item does not
// exist in the bag, it should silently do nothing.
func (b *Bag) Remove(i int) {
	for idx, item := range b.items {
		if item == i {
			b.items = append(b.items[0:idx], b.items[idx+1:len(b.items)]...)
			return
		}
	}
}

// Contains returns true if the given item exists in the bag, and false
// otherwise.
func (b *Bag) Contains(i int) bool {
	for _, item := range b.items {
		if item == i {
			return true
		}
	}
	return false
}

// Size returns the number of items in the bag.
func (b *Bag) Size() int {
	return len(b.items)
}
