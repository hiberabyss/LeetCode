package main

/*
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Easy (52.18%)
 * Total Accepted:    32.7K
 * Total Submissions: 62.7K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array.
 * (If there is no island, the maximum area is 0.)
 *
 * Example 1:
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6.
 *
 * Note the answer is not 11, because the island must be connected
 * 4-directionally.
 *
 *
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 *
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 *
 */

var dx = []int{-1, 1, 0, 0}
var dy = []int{0, 0, 1, -1}

func max(x, y int) int {
	if x >= y {
		return x
	}

	return y
}

func maxAreaOfIsland(grid [][]int) int {
	M := len(grid)
	N := len(grid[0])

	res := 0
	visited := make([][]bool, M)

	for i := 0; i < M; i++ {
		visited[i] = make([]bool, N)
	}

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if visited[i][j] || grid[i][j] == 0 {
				continue
			}

			que := []int{i*N + j}
			visited[i][j] = true
			curArea := 0

			for len(que) > 0 {
				x := que[0] / N
				y := que[0] % N

				que = que[1:]

				curArea++

				for d := 0; d < 4; d++ {
					nx := x + dx[d]
					ny := y + dy[d]

					if nx < M && nx >= 0 && ny < N && ny >= 0 &&
						!visited[nx][ny] && grid[nx][ny] >= 1 {
						que = append(que, nx*N+ny)
						visited[nx][ny] = true
					}
				}
			}

			res = max(res, curArea)
		}
	}

	return res
}
