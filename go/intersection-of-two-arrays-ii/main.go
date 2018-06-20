package main

func intersect(nums1 []int, nums2 []int) []int {
	nm := make(map[int]int)

	for _, v := range nums1 {
		nm[v]++
	}

	var res []int
	for _, v := range nums2 {
		if nm[v] > 0 {
			res = append(res, v)
			nm[v]--
		}
	}

	return res
}
