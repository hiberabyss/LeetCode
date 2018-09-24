package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestCanConstruct(t *testing.T) {
	assert.Equal(t, false, canConstruct("a", "b"))
	assert.Equal(t, false, canConstruct("aa", "ab"))
	assert.Equal(t, true, canConstruct("aa", "aba"))
}
