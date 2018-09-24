package main

import "testing"
import "github.com/stretchr/testify/assert"

func buildList(arr []int) *ListNode {
	root := &ListNode{}

	cur := root
	for _, val := range arr {
		cur.Next = &ListNode{Val: val}
		cur = cur.Next
	}

	return root.Next
}

func isListEqual(l1, l2 *ListNode) bool {
	for l1 != nil && l2 != nil {
		if l1.Val != l2.Val {
			return false
		}

		l1 = l1.Next
		l2 = l2.Next
	}

	return l1 == l2
}

func TestAddTwoNumbers(t *testing.T) {
	assert.Equal(
		t,
		true,
		isListEqual(addTwoNumbers(buildList([]int{2, 4, 3}), buildList([]int{5, 6, 4})), buildList([]int{7, 0, 8})),
	)
}
