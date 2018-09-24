package main

import (
	"container/list"
)

/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (38.58%)
 * Total Accepted:    110.9K
 * Total Submissions: 286.8K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a queue using stacks.
 *
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 *
 *
 * Example:
 *
 *
 * MyQueue queue = new MyQueue();
 *
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 *
 * Notes:
 *
 *
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 */
type MyQueue struct {
	Stack1, Stack2 *list.List
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{list.New(), list.New()}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	for e := this.Stack1.Front(); e != nil; e = e.Next() {
		this.Stack2.PushFront(e.Value)
	}
	this.Stack1 = list.New()
	this.Stack2.PushFront(x)

	for e := this.Stack2.Front(); e != nil; e = e.Next() {
		this.Stack1.PushFront(e.Value)
	}
	this.Stack2 = list.New()
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	elem := this.Stack1.Front()
	this.Stack1.Remove(elem)
	return elem.Value.(int)
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	return this.Stack1.Front().Value.(int)
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.Stack1.Len() == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
