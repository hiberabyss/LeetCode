package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(t, []int{-1, 3, -1}, nextGreaterElement([]int{4, 1, 2}, []int{1, 3, 4, 2}))
}
