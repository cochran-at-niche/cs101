package bag

// Bag is a simple abstract data type (ADT) for storing items. It has methods
// for adding and removing items, checking if a given item exists in the bag,
// and getting the number of items stored in the bag.
type Bag struct {
	Items []int
}

// NewBag is used to create an instance of a Bag.
func NewBag() *Bag {
	return &Bag{}
}

// Add inserts an item into the bag. The bag should accept and store duplicate
// items (i.e. it is not a set).
func (b *Bag) Add(i int) {
	b.Items = append(b.Items, i)
	return
}

// Remove takes an item out of the bag, if it exists. If there are duplicate
// items in the bag, it should only remove one of them. If the item does not
// exist in the bag, it should silently do nothing.
func (b *Bag) Remove(i int) {
	// First, find the index of the item we want to remove from the bag
	idx := -1
	for k, item := range b.Items {
		if item == i {
			idx = k
			break
		}
	}

	// If a match was found, remove that element from our slice of Items
	// Otherwise, do nothing
	if idx >= 0 {
		b.remove_idx(idx)
	}

	return
}

func (b *Bag) remove_idx(idx int) {
	// Swap the item at idx with the last item located at lastidx
	lastidx := len(b.Items) - 1
	b.Items[lastidx], b.Items[idx] = b.Items[idx], b.Items[lastidx]

	// Truncate the bag to all but the last item
	b.Items = b.Items[:lastidx]

	return
}

// Contains returns true if the given item exists in the bag, and false
// otherwise.
func (b *Bag) Contains(i int) bool {
	for _, item := range b.Items {
		if item == i {
			return true
		}
	}
	return false
}

// Size returns the number of items in the bag.
func (b *Bag) Size() int {
	return len(b.Items)
}
