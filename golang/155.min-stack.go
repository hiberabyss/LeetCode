package main

import "container/list"

/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (31.96%)
 * Total Accepted:    197.9K
 * Total Submissions: 617.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 *
 *
 * pop() -- Removes the element on top of the stack.
 *
 *
 * top() -- Get the top element.
 *
 *
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 */
type MinStack struct {
	Data *list.List
	Mins *list.List
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{list.New(), list.New()}
}

func (this *MinStack) Push(x int) {
	this.Data.PushBack(x)
	if this.Mins.Len() == 0 || x <= this.Mins.Back().Value.(int) {
		this.Mins.PushBack(x)
	}
}

func (this *MinStack) Pop() {
	if this.Data.Len() > 0 {
		back := this.Data.Back()
		this.Data.Remove(back)

		if back.Value == this.Mins.Back().Value {
			this.Mins.Remove(this.Mins.Back())
		}
	}
}

func (this *MinStack) Top() int {
	if this.Data.Len() > 0 {
		return this.Data.Back().Value.(int)
	}

	return 0
}

func (this *MinStack) GetMin() int {
	if this.Mins.Len() > 0 {
		return this.Mins.Back().Value.(int)
	}
	return 0
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
