package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(t, 5, findKthLargest([]int{3,2,1,5,6,4}, 2))
}
