package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestIslandPerimeter(t *testing.T) {
	assert.Equal(t, 0, islandPerimeter([][]int {}))

	var i1 = [][]int {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}}
	assert.Equal(t, 16, islandPerimeter(i1))

	var i2 = [][]int {{0,1,0}, {0,0,0}}
	assert.Equal(t, 4, islandPerimeter(i2))
}
