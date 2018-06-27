package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	var grid = [][]int {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0},
	}

	grid2 := [][]int {
		{1,1,0,0,0},
		{1,1,0,0,0},
		{0,0,0,1,1},
		{0,0,0,1,1},
	}

	assert.Equal(t, 6, maxAreaOfIsland(grid))
	assert.Equal(t, 4, maxAreaOfIsland(grid2))
}
