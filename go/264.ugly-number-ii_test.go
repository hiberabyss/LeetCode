package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	// assert.Equal(t, 12, nthUglyNumber(10))
	assert.Equal(t, 15, nthUglyNumber(11))
}
