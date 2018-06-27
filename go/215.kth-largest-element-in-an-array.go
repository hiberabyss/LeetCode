package main

import (
	"container/heap"
)

/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (41.43%)
 * Total Accepted:    223.9K
 * Total Submissions: 539.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

type IntHeap struct {
	Data []int
}

func findKthLargest(nums []int, k int) int {
	h := &IntHeap{Data: nums}
	heap.Init(h)
	for i := 1; i < k; i++ {
		heap.Pop(h)
	}

	return heap.Pop(h).(int)
}

func (h IntHeap) Len() int {
	return len(h.Data)
}

func (h IntHeap) Less(i int, j int) bool {
	return h.Data[i] > h.Data[j]
}

func (h IntHeap) Swap(i int, j int) {
	h.Data[i], h.Data[j] = h.Data[j], h.Data[i]
}

func (h *IntHeap) Push(x interface{}) {
	h.Data = append(h.Data, x.(int))
}

func (h *IntHeap) Pop() (res interface{}) {
	n := len(h.Data)
	res, h.Data = h.Data[n-1], h.Data[:n-1]
	return
}
