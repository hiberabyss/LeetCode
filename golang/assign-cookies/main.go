package main

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)

	cnt := 0
	for i, j := 0, 0; i < len(s) && j < len(g); {
		if s[i] < g[j] {
			i++
			continue
		}

		i, j, cnt = i+1, j+1, cnt+1
	}

	return cnt
}
