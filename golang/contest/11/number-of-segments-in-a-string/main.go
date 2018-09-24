package main

import "strings"

func countSegments1(s string) int {
	if s == "" {
		return 0
	}
	arr := strings.Split(s, " ")
	return len(arr)
}

func countSegments(s string) int {
	res := 0

	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			continue
		}

		res++
		for i < len(s) && s[i] != ' ' {
			i++
		}
	}

	return res
}

