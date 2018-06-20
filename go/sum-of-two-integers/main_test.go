package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestGetSum(t *testing.T) {
	assert.Equal(t, 3, getSum(1, 2))
	assert.Equal(t, 4, getSum(2, 2))
	assert.Equal(t, -4, getSum(-2, -2))
	assert.Equal(t, 0, getSum(-2, 2))
}
