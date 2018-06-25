package main
/*
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.81%)
 * Total Accepted:    28.7K
 * Total Submissions: 87.3K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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

var maxLen int

func longestUnivaluePath(root *TreeNode) int {
	maxLen = 0
	arrowLength(root)
	return maxLen
}

func arrowLength(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftLen := arrowLength(root.Left)
	rightLen := arrowLength(root.Right)

	var arrowLeftLen int
	var arrowRightLen int

	if root.Left != nil && root.Val == root.Left.Val {
		arrowLeftLen = leftLen + 1
	}

	if root.Right != nil && root.Val == root.Right.Val {
		arrowRightLen = rightLen + 1
	}

	maxLen = max(maxLen, arrowLeftLen + arrowRightLen)

	return max(arrowLeftLen, arrowRightLen)
}

func max(x, y int) int {
    if x >= y {
        return x
    }

    return y
}
