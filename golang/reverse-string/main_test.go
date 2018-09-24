package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestReverseString(t *testing.T) {
	assert.Equal(t, "olleH", reverseString("Hello"))
	assert.Equal(t, "!dlrow & olleH", reverseString("Hello & world!"))
	assert.Equal(t, ".snug & raw was I ere I saw war & gunS", reverseString("Snug & raw was I ere I saw war & guns."))
}
