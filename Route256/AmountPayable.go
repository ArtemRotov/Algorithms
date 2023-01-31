package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var testCount int
	var input = []int{}
	fmt.Fscan(in, &testCount)

	for i := 0; i < testCount; i++ {
		var value int
		fmt.Fscan(in, &value)
		for j := 0; j < value; j++ {
			var val int
			fmt.Fscan(in, &val)
			input = append(input, val)
		}
		fmt.Fprintln(out, solution(input))

		input = nil
	}
}

func solution(slice []int) int {
	sum := 0
	sort.Ints(slice)
	for i := 0; i < len(slice); i++ {
		if (i < len(slice)-2) && (slice[i] == slice[i+1]) && (slice[i+1] == slice[i+2]) {
			sum += slice[i] * 2
			i += 2
		} else {
			sum += slice[i]
		}
	}
	return sum
}
