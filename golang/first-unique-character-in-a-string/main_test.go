package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFirstUniqChar(t *testing.T) {
	assert.Equal(t, -1, firstUniqChar("aa"))
	assert.Equal(t, 0, firstUniqChar("leetcode"))
	assert.Equal(t, 2, firstUniqChar("loveleetcode"))
}
