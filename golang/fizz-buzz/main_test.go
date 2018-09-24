package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestFizzBuzz(t *testing.T) {
	res := []string {
		"1",
		"2",
		"Fizz",
		"4",
		"Buzz",
		"Fizz",
		"7",
		"8",
		"Fizz",
		"Buzz",
		"11",
		"Fizz",
		"13",
		"14",
		"FizzBuzz",
	}

	assert.Equal(t, res, fizzBuzz(15))
}
