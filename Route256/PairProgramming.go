package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var testCount int
	fmt.Fscan(in, &testCount)

	for i := 0; i < testCount; i++ {
		var cnt int
		fmt.Fscan(in, &cnt)

		var input []int

		for j := 0; j < cnt; j++ {
			var val int
			fmt.Fscan(in, &val)
			input = append(input, val)
		}
		solution(input, out)
	}
}

func solution(input []int, w *bufio.Writer) {

	const Max int = 999
	for i := 0; i < len(input); i++ {

		if input[i] == Max {
			continue
		}

		value := Max
		var save1 int
		var save2 int

		for j := 0; j < len(input); j++ {
			if i == j || input[j] == Max {
				continue
			}

			tmp := int(math.Abs(float64(input[i] - input[j])))

			if tmp < value {
				value = tmp
				save1 = i
				save2 = j
			}
		}

		fmt.Fprintf(w, "%d %d\n", save1+1, save2+1)
		input[save1] = Max
		input[save2] = Max
	}

	fmt.Fprintln(w)
}

