package main

func intersection(nums1 []int, nums2 []int) []int {
	nm := make(map[int]bool)

	for _, v := range nums1 {
		nm[v] = true
	}

	res := []int {}
	for _, v := range nums2 {
		if nm[v] {
			res = append(res, v)
			nm[v] = false
		}
	}

	return res
}
