package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	grid := [][]int {
		{4,3,8,4},
		{9,5,1,9},
		{2,7,6,2},
	}

	assert.Equal(t, 1, numMagicSquaresInside(grid))
}
