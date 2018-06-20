package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestCountSegment(t *testing.T) {
	assert.Equal(t, 5, countSegments("Hello, my name is John"))
}
