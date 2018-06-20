package main

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	next := head.Next
	head.Next = nil
	res := reverseList(next)
	next.Next = head
	return res
}

func reverseList1(head *ListNode) *ListNode {
	var pre *ListNode
	for cur := head; cur != nil; {
		next := cur.Next;
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
