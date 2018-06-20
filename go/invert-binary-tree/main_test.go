package main

import "testing"
import "github.com/stretchr/testify/assert"

func buildBinTree(t []int) *TreeNode {
	N := len(t)
	if N < 1 {
		return nil
	}

	nodes := make([]*TreeNode, N+1)

	for i := 1; i < len(t); i++ {
		if t[i] > 0 {
			nodes[i] = &TreeNode{Val: t[i]}
		}
	}

	for i := 1; 2*i < len(t); i++ {
		if nodes[i] == nil {
			continue
		}

		nodes[i].Left = nodes[2*i]
		if 2*i + 1 < len(t) {
			nodes[i].Right = nodes[2*i+1]
		}
	}

	return nodes[1]
}

func isTreeEqual(t1, t2 *TreeNode) bool {
	if t1 == nil && t2 == nil {
		return true
	}

	if t1 == nil || t2 == nil {
		return false;
	}

	if t1.Val != t2.Val {
		return false
	}

	return isTreeEqual(t1.Left, t2.Left) && isTreeEqual(t1.Right, t2.Right)
}


func TestInvertTree(t *testing.T) {
	nodes_before := []int {0, 4, 2, 7, 1, 3, 6, 9}
	nodes_after  := []int {0, 4, 7, 2, 9, 6, 3, 1}
	r1 := buildBinTree(nodes_before)
	r2 := buildBinTree(nodes_after)
	assert.Equal(t, true, isTreeEqual(r2, invertTree(r1)))
}
