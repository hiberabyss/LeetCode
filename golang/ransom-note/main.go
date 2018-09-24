package main

func canConstruct(ransomNote string, magazine string) bool {
	cm := make(map[rune]int)

	for _, c := range magazine {
		cm[c]++
	}

	for _, c := range ransomNote {
		if cm[c] <= 0 {
			return false
		}

		cm[c]--
	}

	return true
}
