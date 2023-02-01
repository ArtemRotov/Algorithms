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
	fmt.Fscan(in, &testCount)

	for i := 0; i < testCount; i++ {
		var n, m int
		fmt.Fscan(in, &n, &m)
		var input [][]int

		for j := 0; j < n; j++ {
			var sl []int
			for k := 0; k < m; k++ {
				var val int
				fmt.Fscan(in, &val)
				sl = append(sl, val)
			}
			input = append(input, sl)
		}
		var cc int
		var clicks []int
		fmt.Fscan(in, &cc)
		for l := 0; l < cc; l++ {
			var v int
			fmt.Fscan(in, &v)
			clicks = append(clicks, v)
		}
		solution(input, clicks, out)
	}

}

func solution(input [][]int, clicks []int, w *bufio.Writer) {
	save := -999
	for _, num := range clicks {
		if save == num {
			continue
		}
		sort.SliceStable(input, func(i2, j int) bool {
			return input[i2][num-1] < input[j][num-1]
		})
		save = num
	}
	for _, val := range input {
		for _, v := range val {
			fmt.Fprintf(w, "%d ", v)
		}
		fmt.Fprintf(w, "\n")
	}
	fmt.Fprintln(w)
}

