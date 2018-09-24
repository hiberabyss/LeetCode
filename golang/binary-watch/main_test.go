package main

import (
	"sort"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestReadBinary(t *testing.T) {
	strs := []string{"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"}

	sort.Strings(strs)
	res := readBinaryWatch(1)
	// sort.Strings(res)
	sort.Sort(sort.StringSlice(res))
	assert.Equal(t, strs, res)
}
