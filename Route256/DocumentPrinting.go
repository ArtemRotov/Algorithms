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
		var k int
		fmt.Fscan(in, &k)
 
		var str string
		fmt.Fscan(in, &str)
 
		solution(k, str, out)
	}
}
 
func solution(k int, str string, w *bufio.Writer) {
	m := make(map[int]int)
	for i := 1; i <= k; i++ {
		m[i] = 0
	}
	s := strings.Split(str, ",")
 
	for _, str1 := range s {
		if !strings.Contains(str1, "-") {
			v, _ := strconv.Atoi(str1)
			m[v]++
		} else {
			newStrs := strings.Split(str1, "-")
			first, _ := strconv.Atoi(newStrs[0])
			second, _ := strconv.Atoi(newStrs[1])
			for j := first; j <= second; j++ {
				m[j]++
			}
		}
	}
 
	var out []int
	for key, val := range m {
		if val == 0 {
			out = append(out, key)
		}
	}
 
	sort.Ints(out)
	if len(out) == 1 {
		fmt.Fprintln(w, out[0])
		return
	}
	var output string
	save := -10000
	var flag bool
	for i := 0; i < len(out); i++ {
		if i == 0 {
			output += strconv.Itoa(out[i])
			save = out[i]
			continue
		}
 
		if save+1 == out[i] {
			if i == len(out)-1 {
				output += "-"
				output += strconv.Itoa(out[i])
				break
			}
			flag = true
			save = out[i]
			continue
		}
 
		if flag {
			output += "-"
			output += strconv.Itoa(save)
			output += ","
		}
		if flag {
			output += strconv.Itoa(out[i])
			save = out[i]
			flag = false
		} else {
			output += ","
			output += strconv.Itoa(out[i])
			save = out[i]
		}
	}
	fmt.Fprintln(w, output)
}
