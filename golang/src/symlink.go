package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) != 3 {
		fmt.Printf("Usage: %s <src> <dest>\n", os.Args[0])
		return
	}
	doSymlink(os.Args[1], os.Args[2])
}

func doSymlink(oldPath, newPath string) error {
	if err := os.Symlink(oldPath, newPath); err != nil {
		die(err)
	}
	return nil
}

func die(e error) {
	fmt.Fprintf(os.Stderr, "%s\n", e.Error())
	os.Exit(1)
}
