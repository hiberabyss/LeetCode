package main

func reverseString(s string) string {
	str := []rune(s)

	var i, j int;

	for i, j := 0, len(str) - 1; i < j; i, j = i+1, j-1 {
		str[i], str[j] = str[j], str[i]
	}

	return string(str)
}
