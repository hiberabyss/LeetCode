package main

import "fmt"

/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (42.00%)
 * Total Accepted:    166.5K
 * Total Submissions: 396.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
func binaryTreePaths(root *TreeNode) []string {
	res := []string{}
	if root == nil {
		return res
	}

	if root.Left == nil && root.Right == nil {
		return []string{fmt.Sprintf("%d", root.Val)}
	}

	subPaths := []string {}
	if root.Left != nil {
		subPaths = append(subPaths, binaryTreePaths(root.Left)...)
	}

	if root.Right != nil {
		subPaths = append(subPaths, binaryTreePaths(root.Right)...)
	}

	for _, path := range subPaths {
		res = append(res, fmt.Sprintf("%d->%s", root.Val, path))
	}

	return res
}
