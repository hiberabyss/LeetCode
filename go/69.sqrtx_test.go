package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestMySqrt(t *testing.T) {
	assert.Equal(t, 2, mySqrt(8))
}
