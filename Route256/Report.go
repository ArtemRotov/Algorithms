package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var count int
	fmt.Fscan(in, &count)

	for i := 0; i < count; i++ {
		var cnt int
		var input []int
		fmt.Fscan(in, &cnt)
		for j := 0; j < cnt; j++ {
			var val int
			fmt.Fscan(in, &val)
			input = append(input, val)
		}
		solution(input, out)
	}
}

func solution(input []int, w *bufio.Writer) {
	m := make(map[int]int)
	last := 0
	for _, val := range input {

		_, ok := m[val]
		if !ok {
			m[val]++
			last = val
		} else {
			if last == val {
				m[val]++
				last = val
			} else {
				fmt.Fprintln(w, "NO")
				return
			}
		}
	}
	fmt.Fprintln(w, "YES")
}

