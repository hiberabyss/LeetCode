package main

import "testing"
import "github.com/stretchr/testify/assert"


func TestFindRadius(t *testing.T) {
	house, heater := []int {1, 2, 3}, []int {2}
	assert.Equal(t, 1, findRadius(house, heater))

	house, heater = []int {1, 2, 3, 4}, []int {1, 4}
	assert.Equal(t, 1, findRadius(house, heater))
}
 

func TestLowerBound(t *testing.T) {
	arr := []int {1, 2, 3, 4}
	assert.Equal(t, 0, lowerBound(arr, 1))
	assert.Equal(t, 3, lowerBound(arr, 4))
	assert.Equal(t, 4, lowerBound(arr, 5))
	assert.Equal(t, 1, upperBound(arr, 1))
	assert.Equal(t, 4, upperBound(arr, 4))
	assert.Equal(t, 4, upperBound(arr, 5))

	arr = []int {1, 1, 1, 1, 1}
	assert.Equal(t, 0, lowerBound(arr, 1))
	assert.Equal(t, 5, lowerBound(arr, 2))
	assert.Equal(t, 5, upperBound(arr, 1))
	assert.Equal(t, 0, upperBound(arr, 0))
}
