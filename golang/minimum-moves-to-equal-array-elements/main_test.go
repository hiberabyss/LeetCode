package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestMinMoves(t *testing.T) {
	assert.Equal(t, 0, minMoves([]int {1, 1}))
	assert.Equal(t, 3, minMoves([]int {1, 2, 3}))
	assert.Equal(t, 6, minMoves([]int {1, 2, 3, 4}))
	assert.Equal(t, 2147483646, minMoves([]int {1, 2147483647}))
}
