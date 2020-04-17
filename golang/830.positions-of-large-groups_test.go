package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(t, [][]int{{3, 6}}, largeGroupPositions("abbxxxxzzy"))
}
