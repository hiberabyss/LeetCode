package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	que := Constructor()
	que.Push(1)
	que.Push(2)
	assert.Equal(t, 1, que.Peek())
	// que.Push(3)
	assert.Equal(t, 1, que.Pop())
}

func TestFunc1(t *testing.T) {
	que := Constructor()
	que.Push(1)
	que.Push(2)
	assert.Equal(t, 1, que.Peek())
	assert.Equal(t, 1, que.Pop())
	assert.Equal(t, 2, que.Pop())
	assert.Equal(t, true, que.Empty())
}
