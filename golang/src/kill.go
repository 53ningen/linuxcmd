package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Printf("Usage: %s <pid>\n", os.Args[0])
		return
	}
	for i, v := range os.Args {
		if i == 0 {
			continue
		}
		pid, err := strconv.Atoi(v);
		if err != nil {
			die(err)
		}
		doKill(pid)
	}
}

func doKill(pid int) error {
	procs, err := os.FindProcess(pid)
	if err != nil {
		die(err)
	}
	err = procs.Kill()
	if err != nil {
		die(err)
	}
	return nil
}

func die(e error) {
	fmt.Fprintf(os.Stderr, "%s\n", e.Error())
	os.Exit(1)
}
