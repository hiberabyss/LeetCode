/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (47.06%)
 * Total Accepted:    49.2K
 * Total Submissions: 104.3K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
    }
    
    int get(int key) {
        if (m_.find(key) == m_.end()) {
            return -1;
        }

        auto node = m_[key];
        node->moveFront(l_);

        return node->val;
    }

    void put(int key, int value) {
        if (m_.find(key) != m_.end()) {
            m_[key]->val = value;
            m_[key]->moveFront(l_);
        } else if (size_ >= capacity_) {
            auto node = l_.pre;
            m_.erase(node->key);

            // std::cout << " put, key: " << key << ", val: " << value << "; node key: "
            //         << node->key << std::endl;
            node->moveFront(l_);
            node->val = value;
            node->key = key;
            m_[key] = node;
        } else {
            auto newNode = new ListNode(value, key);
            m_[key] = newNode;
            newNode->addNode(l_);
            size_++;
        }
    }

    struct ListNode {
        int val;
        int key;
        ListNode* pre = nullptr, * next = nullptr;
        ListNode(int v, int k) : val(v), key(k) {}
        ListNode() {}

        void addNode(ListNode& l) {
            this->next = l.next;
            if (this->next != nullptr) {
                this->next->pre = this;
            }
            if (l.pre == nullptr) {
                l.pre = this;
            }
            l.next = this;
        }

        void moveFront(ListNode& l) {
            if (this->pre == nullptr) {
                return;
            }
            auto pre = this->pre;
            pre->next = this->next;
            if (pre->next != nullptr) {
                pre->next->pre = pre;
            } else {
                l.pre = pre;
            }

            this->pre = nullptr;
            this->next = l.next;
            this->next->pre = this;
            l.next = this;
        }
    };

    int capacity_ = 0;
    int size_ = 0;
    ListNode l_;
    unordered_map<int, ListNode*> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
