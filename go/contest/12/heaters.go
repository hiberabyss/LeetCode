package main

import "sort"

// find first element >= x
// find first element > x

func lowerBound(arr []int, x int) int {
	i, j := 0, len(arr)
	for i < j {
		mid := (i+j)/2
		if arr[mid] < x {
			i = mid + 1
		} else {
			j = mid
		}
	}
	return i
}

func upperBound(arr []int, x int) int {
	i, j := 0, len(arr)
	for i < j {
		mid := (i+j)/2
		if arr[mid] <= x {
			i = mid + 1
		} else {
			j = mid
		}
	}
	return i
}


func findRadius(houses []int, heaters []int) int {
	sort.Ints(heaters)

	maxMin := func(x, y int) (int, int) {
		if x > y {
			return x, y
		}
		return y, x
	}

	abs := func(x int) int {
		if x < 0 {
			return -x
		}
		return x
	}

	getMinRadiusForPosition := func(heaters []int, position int) (res int) {
		N := len(heaters)
		i, j := 0, N
		for i < j {
			mid := (i + j) / 2
			if heaters[mid] < position {
				i = mid + 1
			} else {
				j = mid
			}
		}

		if i == N {
			res = abs(position - heaters[i-1])
		} else if i == 0 {
			res = abs(heaters[0] - position)
		} else {
			_, res = maxMin(heaters[i] - position, position - heaters[i-1])
		}
		return res
	}

	res := 0
	for _, v := range houses {
		res, _ = maxMin(res, getMinRadiusForPosition(heaters, v))
	}

	return res
}
