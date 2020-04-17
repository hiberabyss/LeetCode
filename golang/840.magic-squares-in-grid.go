package main

/*
 * [870] Magic Squares In Grid
 *
 * https://leetcode.com/problems/magic-squares-in-grid/description/
 *
 * algorithms
 * Easy (33.80%)
 * Total Accepted:    7K
 * Total Submissions: 20.5K
 * Testcase Example:  '[[4,3,8,4],[9,5,1,9],[2,7,6,2]]'
 *
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to
 * 9 such that each row, column, and both diagonals all have the same sum.
 *
 * Given an grid of integers, how many 3 x 3 "magic square" subgrids are
 * there?  (Each subgrid is contiguous).
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[4,3,8,4],
 * ⁠       [9,5,1,9],
 * ⁠       [2,7,6,2]]
 * Output: 1
 * Explanation:
 * The following subgrid is a 3 x 3 magic square:
 * 438
 * 951
 * 276
 *
 * while this one is not:
 * 384
 * 519
 * 762
 *
 * In total, there is only one magic square inside the given grid.
 *
 *
 * Note:
 *
 *
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * 0 <= grid[i][j] <= 15
 *
 *
 */
func numMagicSquaresInside(grid [][]int) int {
	M := len(grid)
	N := len(grid[0])

	res := 0
	for i := 0; i+2 < M; i++ {
		for j := 0; j+2 < N; j++ {
			if isMagic(grid, i, j) {
				res++
			}
		}
	}

	return res
}

func isMagic(grid [][]int, x int, y int) bool {
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			num := grid[x+i][y+j]
			if num < 1 || num > 9 {
				return false
			}
		}
	}

	sum := grid[x][y] + grid[x][y+1] + grid[x][y+2]

	for i := 1; i < 3; i++ {
		if grid[x+i][y]+grid[x+i][y+1]+grid[x+i][y+2] != sum {
			return false
		}
	}

	for i := 0; i < 3; i++ {
		if grid[x][y+i]+grid[x+1][y+i]+grid[x+2][y+i] != sum {
			return false
		}
	}

	if grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2] != sum {
		return false
	}

	if grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y] != sum {
		return false
	}

	return true
}
