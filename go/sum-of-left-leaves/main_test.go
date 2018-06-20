package main

import "testing"
import "github.com/stretchr/testify/assert"

func buildTree(arr []int) *TreeNode {
	nodes := make([]*TreeNode, len(arr)+1)

	for i, v := range arr {
		if v > 0 {
			nodes[i+1] = &TreeNode{Val: v}
		}
	}

	for i := 1; 2*i < len(nodes); i++ {
		nodes[i].Left = nodes[2*i]
		if 2*i+1 < len(nodes) {
			nodes[i].Right = nodes[2*i+1]
		}
	}

	return nodes[1]
}

func TestSumOfLeftLeaves(t *testing.T) {
	arr := []int{3, 9, 20, 0, 0, 15, 7}
	assert.Equal(t, 24, sumOfLeftLeaves(buildTree(arr)))

	arr = []int {1,2,3,4,5}
	assert.Equal(t, 4, sumOfLeftLeaves(buildTree(arr)))
}
