package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(t, 1, findRadius([]int{1, 2, 3, 4}, []int{1, 4}))
}
