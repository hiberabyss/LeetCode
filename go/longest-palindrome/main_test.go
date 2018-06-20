package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestLogestPalindrome(t *testing.T) {
	assert.Equal(t, 7, longestPalindrome("abccccdd"))
}
