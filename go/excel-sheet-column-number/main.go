package main

func titleToNumber(s string) int {
	res := 0

	for _, v := range s {
		res = res * 26 + (int(v)-int('A')) + 1
	}

	return res
}
