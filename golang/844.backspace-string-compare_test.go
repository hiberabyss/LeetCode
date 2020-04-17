package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(t, false, backspaceCompare("a#c", "b"))
	assert.Equal(t, true, backspaceCompare("ab##", "c#d#"))
	assert.Equal(t, true, backspaceCompare("xywrrmp", "xywrrmu#p"))
}
