package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFunc(t *testing.T) {
	assert.Equal(
		t,
		"Imaa peaksmaaa oatGmaaaa atinLmaaaaa",
		toGoatLatin("I speak Goat Latin"),
	)
}
