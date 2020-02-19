package main

import (
	"fmt"

	"github.com/google/btree"
)

const btreeDegree = 4

func main() {
	fmt.Println("\nSequential Scan")
	sequentialScan()

	fmt.Println("\nSequential Scan With Filter")
	sequentialScanWithFilter()

	fmt.Println("\nIndex Scan")
	indexScan()

	fmt.Println("\nNested Loop Join")
	nestedLoopJoin()

	fmt.Println("\nNested Loop Join (Full)")
	nestedLoopJoinFull()

	fmt.Println("\nIndex Scan Join")
	indexScanJoin()

	fmt.Println("\nHash Join")
	hashJoin()
}

type FactSchema struct {
	ID    int
	GUID  string
	Name  string
	Label string
}

type Fact struct {
	ID         int
	EntityGUID string
	FactGUID   string
	Value      interface{}
}

type Result struct {
	FactSchema
	Fact
}

var factSchemaTable = []FactSchema{
	{
		ID:    3480,
		GUID:  "d08caa77-ce62-46f3-b4f4-159203fbef24",
		Name:  "Tuition",
		Label: "Yearly Tuition",
	},
	{
		ID:    4,
		GUID:  "76b06678-04cd-4949-9938-1b6a33b8e073",
		Name:  "TotalStudents",
		Label: "Students",
	},
}

var factTable = []Fact{
	{
		ID:         114171110,
		EntityGUID: "00016c60-f35e-40a3-811c-4c87e6a68b56",
		FactGUID:   "d08caa77-ce62-46f3-b4f4-159203fbef24",
		Value:      9576,
	},
	{
		ID:         114171098,
		EntityGUID: "00016c60-f35e-40a3-811c-4c87e6a68b56",
		FactGUID:   "76b06678-04cd-4949-9938-1b6a33b8e073",
		Value:      250,
	},
	{
		ID:         114171621,
		EntityGUID: "0002e302-4722-41c2-99f7-d8f504655389",
		FactGUID:   "d08caa77-ce62-46f3-b4f4-159203fbef24",
		Value:      11000,
	},
	{
		ID:         114171611,
		EntityGUID: "0002e302-4722-41c2-99f7-d8f504655389",
		FactGUID:   "76b06678-04cd-4949-9938-1b6a33b8e073",
		Value:      138,
	},
}

func sequentialScan() {
	for _, factSchema := range factSchemaTable {
		fmt.Println(factSchema)
	}
}

func sequentialScanWithFilter() {
	for _, factSchema := range factSchemaTable {
		if factSchema.Label == "Yearly Tuition" {
			fmt.Println(factSchema)
		}
	}
}

func (fs FactSchema) Less(than btree.Item) bool {
	return fs.Label < than.(FactSchema).Label
}

func indexScan() {
	index := btree.New(btreeDegree)
	for _, factSchema := range factSchemaTable {
		index.ReplaceOrInsert(factSchema)
	}

	factSchema := index.Get(FactSchema{Label: "Yearly Tuition"})
	fmt.Println(factSchema.(FactSchema))
}

func nestedLoopJoin() {
	for _, factSchema := range factSchemaTable {
		if factSchema.Label == "Yearly Tuition" {
			for _, fact := range factTable {
				if fact.EntityGUID == "00016c60-f35e-40a3-811c-4c87e6a68b56" {
					if factSchema.GUID == fact.FactGUID {
						fmt.Println(Result{
							FactSchema: factSchema,
							Fact:       fact,
						})
					}
				}
			}
		}
	}
}

func nestedLoopJoinFull() {
	for _, factSchema := range factSchemaTable {
		for _, fact := range factTable {
			if factSchema.GUID == fact.FactGUID {
				fmt.Println(Result{
					FactSchema: factSchema,
					Fact:       fact,
				})
			}
		}
	}
}

func (f Fact) Less(than btree.Item) bool {
	if f.EntityGUID == than.(Fact).EntityGUID {
		return f.FactGUID < than.(Fact).FactGUID
	}
	return f.EntityGUID < than.(Fact).EntityGUID
}

func indexScanJoin() {
	index := btree.New(btreeDegree)
	for _, fact := range factTable {
		index.ReplaceOrInsert(fact)
	}

	for _, factSchema := range factSchemaTable {
		if factSchema.Label == "Yearly Tuition" {
			fact := index.Get(Fact{
				EntityGUID: "00016c60-f35e-40a3-811c-4c87e6a68b56",
				FactGUID:   factSchema.GUID,
			})
			fmt.Println(Result{
				FactSchema: factSchema,
				Fact:       fact.(Fact),
			})
		}
	}
}

func hashJoin() {
	hashTable := map[string]FactSchema{}
	for _, factSchema := range factSchemaTable {
		hashTable[factSchema.GUID] = factSchema
	}

	for _, fact := range factTable {
		factSchema := hashTable[fact.FactGUID]
		fmt.Println(Result{
			FactSchema: factSchema,
			Fact:       fact,
		})
	}
}
