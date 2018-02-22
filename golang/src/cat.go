package main

import (
	"fmt"
	"io"
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
		doCat(v)
	}
}

const BUFFER_SIZE = 2048

func doCat(path string) error {
	file, error := os.Open(path)
	if error != nil {
		die(error)
	}
	defer file.Close()

	buf := make([]byte, BUFFER_SIZE)
	for {
		n, error := file.Read(buf)
		if error == io.EOF {
			break
		}
		if error != nil {
			die(error)
		}
		if n == 0 {
			die(error)
		}
		fmt.Print(string(buf[:n]))
	}
	return nil
}

func die(e error) {
	fmt.Fprintf(os.Stderr, "%s\n", e.Error())
	os.Exit(1)
}
