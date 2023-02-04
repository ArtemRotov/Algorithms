package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var count int
	fmt.Fscan(in, &count)

	for i := 0; i < count; i++ {
		var cnt int
		fmt.Fscan(in, &cnt)

		var input []string
		for j := 0; j < cnt; j++ {
			var str string
			fmt.Fscan(in, &str)
			input = append(input, str)
		}
		solution(input, out)
	}
}

func solution(input []string, w *bufio.Writer) {

	m := make(map[string][]int)

	for ind, val := range input {
		news := strings.Replace(val, "-", ":", 1)
		res := strings.Split(news, ":")
		strs := strings.Split(val, "-")

		hour1, _ := strconv.Atoi(res[0])
		min1, _ := strconv.Atoi(res[1])
		sec1, _ := strconv.Atoi(res[2])

		hour2, _ := strconv.Atoi(res[3])
		min2, _ := strconv.Atoi(res[4])
		sec2, _ := strconv.Atoi(res[5])

		if hour1 < 0 || hour1 > 23 || hour2 < 0 || hour2 > 23 {
			fmt.Fprintln(w, "NO")
			return
		}

		if min1 < 0 || min1 > 59 || min2 < 0 || min2 > 59 {
			fmt.Fprintln(w, "NO")
			return
		}

		if sec1 < 0 || sec1 > 59 || sec2 < 0 || sec2 > 59 {
			fmt.Fprintln(w, "NO")
			return
		}

		if strs[0] > strs[1] && strs[0] != "00:00:00" {
			fmt.Fprintln(w, "NO")
			return
		} else {

			_, ok := m[strs[0]]
			if !ok {
				m[strs[0]] = append(m[strs[0]], ind)
			} else {
				fmt.Fprintln(w, "NO")
				return
			}

			_, ok = m[strs[1]]
			if !ok || (strs[0] == strs[1] && len(m[strs[1]]) < 2) {
				m[strs[1]] = append(m[strs[1]], ind)
			} else {
				fmt.Fprintln(w, "NO")
				return
			}
		}
	}

	keys := make([]string, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for l := 0; l < len(keys)-1; l += 2 {
		if len(m[keys[l]]) == 2 {
			l++
			continue
		}

		if m[keys[l]][0] != m[keys[l+1]][0] {
			fmt.Fprintln(w, "NO")
			return
		}
	}
	fmt.Fprintln(w, "YES")
}

