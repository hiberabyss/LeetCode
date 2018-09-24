package main

import (
	"fmt"
	"testing"
)

func TestFunc(t *testing.T) {
	cache := Constructor(2)
	cache.Put(1, 1)
	cache.Put(2, 2)
	fmt.Println(cache.Get(1))
	cache.Put(3, 3)
	fmt.Println(cache.Get(2))

	// assert.Equal(t, )
}
