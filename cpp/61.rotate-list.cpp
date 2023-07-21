/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (40.52%)
 * Total Accepted:    226.6K
 * Total Submissions: 542.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 
 * 0 
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (head == nullptr) {
        return head;
      }

      int N = 0;
      auto* end = head;
      for (auto* n = head; n != nullptr; n = n->next) {
        if (n->next == nullptr) end = n;
        N++;
      }

      k = k % N;
      if (k == 0) {
        return head;
      }

      k = N - k;
      ListNode tmp(0, head);
      auto* pre = &tmp;
      for (int i = 0; i < k; ++i) {
        pre = pre->next;
      }

      tmp.next = pre->next;
      end->next = head;
      pre->next = nullptr;

      return tmp.next;
    }
};
