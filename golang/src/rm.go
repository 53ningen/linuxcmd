package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Printf("%s: file name not given\n", os.Args[0])
		os.Exit(1)
	}
	for i, v := range os.Args {
		if i == 0 {
			continue
		}
		doRm(v)
	}
}

func doRm(path string) error {
	if err := os.RemoveAll(path); err != nil {
		die(err)
	}
	return nil
}

func die(e error) {
	fmt.Fprintf(os.Stderr, "%s\n", e.Error())
	os.Exit(1)
}
