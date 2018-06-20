package main

func firstUniqChar(s string) int {
	cm := make(map[rune]int)

	for _, v := range s {
		cm[v]++
	}

	for i, v := range s {
		if cm[v] == 1 {
			return i
		}
	}

	return -1
}
