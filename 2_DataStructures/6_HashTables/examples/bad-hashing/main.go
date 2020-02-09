package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	file, err := os.Open("/usr/share/dict/words")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	hashes := map[int][]string{}
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		word := scanner.Text()
		var hash int
		for _, r := range word {
			hash += int(r)
		}
		hashes[hash] = append(hashes[hash], word)
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	for hash, words := range hashes {
		fmt.Printf("%d\t%d\n", hash, len(words))
	}
}
