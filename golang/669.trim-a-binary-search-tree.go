package main
/*
 * [669] Trim a Binary Search Tree
 *
 * https://leetcode.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (58.23%)
 * Total Accepted:    36.3K
 * Total Submissions: 62.4K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 
 * Given a binary search tree and the lowest and highest boundaries as L and R,
 * trim the tree so that all its elements lies in [L, R] (R >= L). You might
 * need to change the root of the tree, so the result should return the new
 * root of the trimmed binary search tree.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 * 
 * ⁠ L = 1
 * ⁠ R = 2
 * 
 * Output: 
 * ⁠   1
 * ⁠     \
 * ⁠      2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 * 
 * ⁠ L = 1
 * ⁠ R = 3
 * 
 * Output: 
 * ⁠     3
 * ⁠    / 
 * ⁠  2   
 * ⁠ /
 * ⁠1
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
func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if root == nil {
		return root
	}

	if root.Val < L {
		return trimBST(root.Right, L, R)
	}

	if root.Val > R {
		return trimBST(root.Left, L, R)
	}

	root.Left = trimBST(root.Left, L, R)
	root.Right = trimBST(root.Right, L, R)

	return root
}

func trimBST1(root *TreeNode, L int, R int) *TreeNode {
	if root == nil {
		return root
	}

	if root.Val < L || root.Val > R {
		if root.Left == nil {
			return trimBST(root.Right, L, R)
		}

		if root.Right == nil {
			return trimBST(root.Left, L, R)
		} 

		parent := root
		cur := parent.Right
		for cur.Left != nil {
			parent = cur
			cur = cur.Left
		}

		root.Val = cur.Val
		if parent == root {
			parent.Right = nil
		} else {
			parent.Left = nil
		}

		return trimBST(root, L, R)
	}

	root.Left = trimBST(root.Left, L, R)
	root.Right = trimBST(root.Right, L, R)

	return root
}
