package main

import "strconv"

func readBinaryWatch(num int) []string {
	nm := make(map[int][]string)

	getBinCnt := func(x int) int {
		cnt := 0
		for x != 0 {
			cnt++
			x = x & (x - 1)
		}
		return cnt
	}

	for i := 0; i < 12; i++ {
		for j := 0; j < 60; j++ {
			bcnt := getBinCnt(i) + getBinCnt(j)
			time_str := strconv.Itoa(i) + ":"
			if j < 10 {
				time_str += "0" + strconv.Itoa(j)
			} else {
				time_str += strconv.Itoa(j)
			}

			nm[bcnt] = append(nm[bcnt], time_str)
		}
	}

	return nm[num]
}
