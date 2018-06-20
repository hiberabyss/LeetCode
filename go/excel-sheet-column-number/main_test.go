package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestTitleToNumber(t *testing.T) {
	assert.Equal(t, 1, titleToNumber("A"))
	assert.Equal(t, 27, titleToNumber("AA"))
	assert.Equal(t, 53, titleToNumber("BA"))
}
