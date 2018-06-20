package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestIntersect(t *testing.T) {
	arr1, arr2 := []int {1, 2, 2, 1}, []int {2, 2}
	assert.Equal(t, []int {2, 2}, intersect(arr1, arr2))
}
