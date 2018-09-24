package main

import "testing"
import "github.com/stretchr/testify/assert"

func buildList(nodes []int) *ListNode {
	var head, pre *ListNode
	for _, v := range nodes {
		if pre == nil {
			pre = &ListNode{Val: v}
			head = pre
			continue
		}

		pre.Next = &ListNode{Val: v}
	}
	return head
}

func TestReverseList(t *testing.T) {
	n1, n2 := []int {1, 2, 3}, []int {3, 2, 1}
	h1, h2 := buildList(n1), buildList(n2)
	assert.Equal(t, h2, reverseList(h1))
}


