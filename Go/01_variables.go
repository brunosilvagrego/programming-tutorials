package main

import "fmt"

func main() {
	
	/* Static Type Declaration: var variable_list optional_data_type */
	var x float64 = 20.5
	fmt.Printf("x = %.2f, type = %T\n", x, x)

	/* Dynamic Declaration / Type Inference */
	y := 42
	fmt.Printf("y = %d, type = %T\n", y, y)

	/* Mixed Variable Declaration */
	var a, b, c = 3, 4, "Hello World"  
	fmt.Printf("a = %d, type = %T\n", a, a)
	fmt.Printf("b = %d, type = %T\n", b, b)
	fmt.Printf("c = %s, type = %T\n", c, c)
}