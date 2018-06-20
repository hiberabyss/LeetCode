package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}

	isLeaf := func(node *TreeNode) bool {
		return node != nil && node.Left == nil && node.Right == nil
	}

	if isLeaf(root.Left) {
		return root.Left.Val + sumOfLeftLeaves(root.Right)
	}

	return sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}
