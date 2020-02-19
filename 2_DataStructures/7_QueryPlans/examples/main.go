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

func (fs FactSchema) Less(than btree.Item) bool {
	return fs.Label < than.(FactSchema).Label
}

func (f Fact) Less(than btree.Item) bool {
	if f.EntityGUID == than.(Fact).EntityGUID {
		return f.FactGUID < than.(Fact).FactGUID
	}
	return f.EntityGUID < than.(Fact).EntityGUID
}

var factSchemaTable = []FactSchema{
	{
		ID:    1,
		GUID:  "4dc4d724-53ed-4c0b-be80-e357645f8db1",
		Name:  "Tuition",
		Label: "Yearly Tuition",
	},
	{
		ID:    2,
		GUID:  "7b456ed3-ee0d-4af7-b7a1-82b91ee4fff7",
		Name:  "NetPrice",
		Label: "Net Price",
	},
}

var factTable = []Fact{
	{
		ID:         1,
		EntityGUID: "00219d2b-b49c-4fd4-a361-02ccb1ccd4c4",
		FactGUID:   "4dc4d724-53ed-4c0b-be80-e357645f8db1",
		Value:      1000,
	},
	{
		ID:         2,
		EntityGUID: "00219d2b-b49c-4fd4-a361-02ccb1ccd4c4",
		FactGUID:   "7b456ed3-ee0d-4af7-b7a1-82b91ee4fff7",
		Value:      2000,
	},
	{
		ID:         3,
		EntityGUID: "f18ba1e6-a73c-488f-aba7-ada796a909eb",
		FactGUID:   "4dc4d724-53ed-4c0b-be80-e357645f8db1",
		Value:      3000,
	},
	{
		ID:         4,
		EntityGUID: "f18ba1e6-a73c-488f-aba7-ada796a909eb",
		FactGUID:   "7b456ed3-ee0d-4af7-b7a1-82b91ee4fff7",
		Value:      4000,
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
				if fact.EntityGUID == "00219d2b-b49c-4fd4-a361-02ccb1ccd4c4" {
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

func indexScanJoin() {
	index := btree.New(btreeDegree)
	for _, fact := range factTable {
		index.ReplaceOrInsert(fact)
	}

	for _, factSchema := range factSchemaTable {
		if factSchema.Label == "Yearly Tuition" {
			fact := index.Get(Fact{
				EntityGUID: "00219d2b-b49c-4fd4-a361-02ccb1ccd4c4",
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
