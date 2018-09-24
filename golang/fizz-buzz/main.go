package main

import "strconv"

const FizzStr string = "Fizz"
const BuzzStr string = "Buzz"

func fizzBuzz(n int) []string {
	var res []string

	for i := 1; i <= n; i++ {
		if i%3 == 0 && i%5 == 0 {
			res = append(res, FizzStr+BuzzStr)
		} else if i%3 == 0 {
			res = append(res, FizzStr)
		} else if i%5 == 0 {
			res = append(res, BuzzStr)
		} else {
			res = append(res, strconv.Itoa(i))
		}
	}

	return res
}
