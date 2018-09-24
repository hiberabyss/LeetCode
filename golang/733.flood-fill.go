package main
/*
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (47.80%)
 * Total Accepted:    16.4K
 * Total Submissions: 34.2K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	visited := make(map[int]bool)

	M := len(image)
	N := len(image[0])

	que := []int {sr * N + sc}
	visited[sr*N + sc]  = true

	startColor := image[sr][sc]
	for len(que) > 0 {
		x := que[0] / N
		y := que[0] % N
		que = que[1:]

		for d := 0; d < 4; d++ {
			nx := x + dx[d]
			ny := y + dy[d]

			idx := nx * N + ny

			if nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[idx] && image[nx][ny] == startColor {
				que = append(que, idx)
				visited[idx] = true
			}
		}

		image[x][y] = newColor
	}

	return image
}

var dx = []int {-1, 1, 0, 0}
var dy = []int {0, 0, 1, -1}
