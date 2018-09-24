package main

import (
	"container/list"
)

/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (20.38%)
 * Total Accepted:    183K
 * Total Submissions: 895.8K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 *
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache( 2  capacity  );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 */
type LRUCache struct {
	Map  map[int]*list.Element
	List *list.List
	Cap  int
}

type Node struct {
	Key   int
	Value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Map:  make(map[int]*list.Element),
		List: list.New(),
		Cap:  capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	if val, ok := this.Map[key]; ok {
		this.List.MoveToBack(val)
		return val.Value.(Node).Value
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	N := this.List.Len()

	if elem, ok := this.Map[key]; ok {
		elem.Value = Node{key, value}
		this.List.MoveToBack(elem)
	} else {
		if N >= this.Cap {
			first := this.List.Front()
			key := first.Value.(Node).Key
			delete(this.Map, key)

			this.List.Remove(first)
		}

		this.Map[key] = this.List.PushBack(Node{key, value})
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
