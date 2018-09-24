package main

func longestPalindrome(s string) int {
	nm := make(map[rune]int)
	res := 0
	odd := 0

	for _, v := range s {
		nm[v]++
	}

	for _, v := range nm {
		if v%2 == 1 {
			odd = 1
		}

		res += v/2*2
	}

	return res + odd
}
