package main

func islandPerimeter(grid [][]int) int {
	M := len(grid)

	if M == 0 {
		return 0
	}

	N := len(grid[0])

	res := 0
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if grid[i][j] != 0 {
				if i == 0 || grid[i-1][j] == 0 {
					res++;
				}

				if i+1 == M || grid[i+1][j] == 0 {
					res++;
				}

				if j == 0 || grid[i][j-1] == 0 {
					res++;
				}

				if j+1 == N || grid[i][j+1] == 0 {
					res++;
				}
			}
		}
	}

	return res
}
