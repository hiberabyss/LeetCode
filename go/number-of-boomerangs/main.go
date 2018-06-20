package main

func numberOfBoomerangs(points [][]int) int {
	N := len(points)
	if N == 0 {
		return 0
	}

	dis := func(x, y []int) int {
		return (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1])
	}

	res := 0
	for i := 0; i < N; i++ {
		nm := make(map[int]int)
		for j := 0; j < N; j++ {
			if j == i {
				continue
			}

			d := dis(points[i], points[j])
			res += 2 * nm[d]
			nm[d]++
		}
	}
	return res
}

func numberOfBoomerangs1(points [][]int) int {
	N := len(points)
	if N == 0 {
		return 0
	}

	dis := func(x, y []int) int {
		return (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1])
	}

	res := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			for k := 0; k < N; k++ {
				if i == j || i == k || j == k {
					continue
				}

				if dis(points[i], points[j]) == dis(points[i], points[k]) {
					res++
				}
			}
		}
	}
	return res
}
