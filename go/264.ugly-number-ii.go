package main

import (
	"container/heap"
)

/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.58%)
 * Total Accepted:    78.1K
 * Total Submissions: 232.4K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5.
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 *
 */
func nthUglyNumber(n int) int {
	if n <= 0 {
		return -1
	}

	h := &IntHeap{Data: []int{1}}
	cur := 0

	x := 0
	for cur < n {
		x = heap.Pop(h).(int)
		cur++

		if x%3 > 0 && x%5 > 0 {
			heap.Push(h, x*2)
			heap.Push(h, x*3)
		} else if x%5 > 0 {
			heap.Push(h, x*3)
		}

		heap.Push(h, x*5)

	}

	return x
}

type IntHeap struct {
	Data []int
}

func (h IntHeap) Len() int {
	return len(h.Data)
}

func (h IntHeap) Less(i int, j int) bool {
	return h.Data[i] < h.Data[j]
}

func (h IntHeap) Swap(i int, j int) {
	h.Data[i], h.Data[j] = h.Data[j], h.Data[i]
}

func (h *IntHeap) Push(x interface{}) {
	h.Data = append(h.Data, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	N := h.Len()
	res := h.Data[N-1]
	h.Data = h.Data[:N-1]
	return res
}
