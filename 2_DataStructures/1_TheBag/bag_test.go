package bag

import "testing"

func TestNewBag(t *testing.T) {
	bag := NewBag()
	if bag.Contains(1) {
		t.Errorf("Expected newly initialized bag to not contain 1")
	}
	if bag.Size() != 0 {
		t.Errorf("Expected newly initialized bag to have a size of 0")
	}
}

func TestAdd(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	if !bag.Contains(1) {
		t.Errorf("Expected bag to contain 1 after calling Add(1)")
	}
	if bag.Size() != 1 {
		t.Errorf("Expected bag to have a size of 1 after calling Add(1)")
	}
}

func TestAdd_Multiple(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	bag.Add(2)
	if !bag.Contains(1) {
		t.Errorf("Expected bag to contain 1 after calling Add(1) and Add(2)")
	}
	if !bag.Contains(2) {
		t.Errorf("Expected bag to contain 2 after calling Add(1) and Add(2)")
	}
	if bag.Size() != 2 {
		t.Errorf("Expected bag to have a size of 2 after calling Add(1) and Add(2)")
	}
}

func TestAdd_Many(t *testing.T) {
	bag := NewBag()

	for i := 0; i < 100; i++ {
		bag.Add(i)
	}

	for i := 0; i < 100; i++ {
		if !bag.Contains(i) {
			t.Errorf("Expected bag to contain %d after calling Add(%d)", i, i)
			break
		}
	}

	if bag.Size() != 100 {
		t.Errorf("Expected bag to have a size of 100 after calling Add 100 times")
	}
}

func TestAdd_Duplicates(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	bag.Add(1)
	if !bag.Contains(1) {
		t.Errorf("Expected bag to contain 1 after calling Add(1) twice")
	}
	if bag.Size() != 2 {
		t.Errorf("Expected bag to have a size of 2 after calling Add(1) twice")
	}
}

func TestRemove(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	bag.Remove(1)
	if bag.Contains(1) {
		t.Errorf("Expected bag to not contain 1 after calling Add(1) and Remove(1)")
	}
	if bag.Size() != 0 {
		t.Errorf("Expected bag to have a size of 0 after calling Add(1) and Remove(1)")
	}
}

func TestRemove_Multiple(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	bag.Add(2)

	bag.Remove(1)
	if bag.Contains(1) {
		t.Errorf("Expected bag to not contain 1 after calling Add(1), Add(2), and Remove(1)")
	}
	if !bag.Contains(2) {
		t.Errorf("Expected bag to contain 2 after calling Add(1), Add(2), and Remove(1)")
	}
	if bag.Size() != 1 {
		t.Errorf("Expected bag to have a size of 1 after calling Add(1), Add(2), and Remove(1)")
	}

	bag.Remove(2)
	if bag.Contains(1) {
		t.Errorf("Expected bag to not contain 1 after calling Add(1), Add(2), and Remove(1)")
	}
	if bag.Contains(2) {
		t.Errorf("Expected bag to not contain 2 after calling Add(1), Add(2), Remove(1), and Remove(2)")
	}
	if bag.Size() != 0 {
		t.Errorf("Expected bag to have a size of 0 after calling Add(1), Add(2), Remove(1), and Remove(2)")
	}
}

func TestRemove_Many(t *testing.T) {
	bag := NewBag()

	for i := 0; i < 100; i++ {
		bag.Add(i)
	}

	for i := 0; i < 100; i++ {
		bag.Remove(i)
	}

	for i := 0; i < 100; i++ {
		if bag.Contains(i) {
			t.Errorf("Expected bag to not contain %d after calling Add(%d) and Remove(%d)", i, i, i)
			break
		}
	}

	if bag.Size() != 0 {
		t.Errorf("Expected bag to have a size of 0 after calling Add and Remove 100 times")
	}
}

func TestRemove_NonExistent(t *testing.T) {
	bag := NewBag()
	bag.Remove(1)
	if bag.Contains(1) {
		t.Errorf("Expected bag to not contain 1 after calling Remove(1) on an empty bag")
	}
	if bag.Size() != 0 {
		t.Errorf("Expected bag to have a size of 0 after calling Remove(1) on an empty bag")
	}

	bag.Add(1)
	bag.Remove(2)
	if bag.Contains(2) {
		t.Errorf("Expected bag to not contain 2 after calling Remove(1), Add(1), and Remove(2) on an empty bag")
	}
	if bag.Size() != 1 {
		t.Errorf("Expected bag to have a size of 1 after calling Remove(1), Add(1), and Remove(2) on an empty bag")
	}
}

func TestRemove_Duplicates(t *testing.T) {
	bag := NewBag()
	bag.Add(1)
	bag.Add(1)

	bag.Remove(1)
	if !bag.Contains(1) {
		t.Errorf("Expected bag to contain 1 after calling Add(1) twice and Remove(1) once")
	}
	if bag.Size() != 1 {
		t.Errorf("Expected bag to have a size of 1 after calling Add(1) twice and Remove(1) once")
	}

	bag.Remove(1)
	if bag.Contains(1) {
		t.Errorf("Expected bag to not contain 1 after calling Add(1) twice and Remove(1) twice")
	}
	if bag.Size() != 0 {
		t.Errorf("Expected bag to have a size of 0 after calling Add(1) twice and Remove(1) twice")
	}
}
