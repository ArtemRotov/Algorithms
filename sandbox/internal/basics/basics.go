package basics

import "fmt"

func Sum(x, y int) int {
	return x + y
}

// closure
func InitPrice(price int) func(int) int {
	sum := price
	return func(x int) int {
		sum += x
		return sum
	}
}

func DeferExample() {
	// Дефер - отложенный вызов
	// LIFO

	defer fmt.Println(1)
	defer fmt.Println(2)
	defer fmt.Println(3)
	fmt.Println("NOW")

	//output : NOW 3 2 1
}
