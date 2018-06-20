package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFindContentChildren(t *testing.T) {
	g := []int{2, 3, 4}
	s := []int{1}
	assert.Equal(t, 0, findContentChildren(g, s))

	g = []int{1, 2, 3}
	s = []int{1, 1}
	assert.Equal(t, 1, findContentChildren(g, s))

	g = []int{1, 2}
	s = []int{1, 2, 3}
	assert.Equal(t, 2, findContentChildren(g, s))
}
