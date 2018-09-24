package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	que := Constructor()
	que.Push(1)
	que.Push(2)
	que.Push(3)
	assert.Equal(t, 1, que.Peek())
}
