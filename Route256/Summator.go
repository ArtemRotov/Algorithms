package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var testCount int
	var input = []int{}
	fmt.Fscan(in, &testCount)

	for i := 0; i < testCount*2; i++ {
		var value int
		fmt.Fscan(in, &value)
		input = append(input, value)
	}
	sum(&input, out)
}

func sum(sl *[]int, w io.Writer) {
	for i := 0; i < len(*sl); i++ {
		fmt.Fprintln(w, (*sl)[i]+(*sl)[i+1])
		i++
	}
}
