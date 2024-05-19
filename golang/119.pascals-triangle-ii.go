package main
/*
 * @lc app=leetcode.cn id=119 lang=golang
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode.cn/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (69.02%)
 * Total Accepted:    309.1K
 * Total Submissions: 447.8K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: rowIndex = 0
 * 输出: [1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: rowIndex = 1
 * 输出: [1,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 * 
 */
func getRow(rowIndex int) []int {
	res := []int {1}
	for i := 1; i <= rowIndex; i++ {
		tmp := []int {1}
		for i := 0; i+1 < len(res); i++ {
			tmp = append(tmp, res[i] + res[i+1])
		}
		tmp = append(tmp, 1)

		res = tmp
	}

	return res
}
