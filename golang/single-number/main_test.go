package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestSingleNumber(t *testing.T) {
	assert.Equal(t, singleNumber([]int {1}), 1)
	assert.Equal(t, singleNumber([]int {1, 2, 1}), 2)
}

