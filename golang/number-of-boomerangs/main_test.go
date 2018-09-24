package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestNumberOfBoomerangs(t *testing.T) {
	points := [][]int {[]int {0, 0}, []int {1, 0}, []int {2, 0}}
	assert.Equal(t, 2, numberOfBoomerangs(points))

	points = [][]int {
		[]int {0,  0},
		[]int {1,  0},
		[]int {-1, 0},
		[]int {0,  1},
		[]int {0, -1},
	}
	assert.Equal(t, 20, numberOfBoomerangs(points))
}
