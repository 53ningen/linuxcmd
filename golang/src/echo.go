package main

import (
	"fmt"
	"os"
)

func main() {
	for i, v := range os.Args {
		if i == 0 {
			continue
		}
		var sp = " "
		if i == 1 {
			sp = ""
		}
		fmt.Printf("%s%s", sp, v)
	}
	fmt.Print("\n")
}
