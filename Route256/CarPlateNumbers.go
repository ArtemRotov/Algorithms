package main
 
import (
	"bufio"
	"fmt"
	"os"
	"regexp"
)
 
func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
 
	var count int
	fmt.Fscan(in, &count)
 
	for i := 0; i < count; i++ {
		var str string
		fmt.Fscan(in, &str)
		solution(str, out)
	}
 
}
 
func solution(str string, w *bufio.Writer) {
 
	rregexp := "[A-Z][0-9][0-9][A-Z][A-Z]|[A-Z][0-9][A-Z][A-Z]"
 
	r := regexp.MustCompile(rregexp)
	out := r.ReplaceAllString(str, "")
 
	if len(out) == 0 {
		res := r.FindAllString(str, -1)
		for _, val := range res {
			fmt.Fprintf(w, "%s ", val)
		}
		fmt.Fprint(w, "\n")
	} else {
		fmt.Fprintln(w, "-")
	}
}
