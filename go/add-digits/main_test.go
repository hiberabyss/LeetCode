package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestAddDigits(t *testing.T) {
	assert.Equal(t, addDigits(38), 2)
	assert.Equal(t, addDigits(0), 0)
}
