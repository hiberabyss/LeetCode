package main
/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (42.83%)
 * Total Accepted:    171.3K
 * Total Submissions: 399.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
	var res [][]int
	if root == nil {
		return res
	}

	level := []*TreeNode {root}
	for len(level) > 0 {
		nextLevel := []*TreeNode {}
		levelVal := []int {}
		for len(level) > 0 {
			curNode := level[0]
			levelVal = append(levelVal, curNode.Val)
			level = level[1:]

			if curNode.Left != nil {
				nextLevel = append(nextLevel, curNode.Left)
			}

			if curNode.Right != nil {
				nextLevel = append(nextLevel, curNode.Right)
			}
		}

		level = nextLevel
		res = append([][]int{ levelVal }, res...)
	}

	return res
}
