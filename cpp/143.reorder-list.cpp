/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (59.59%)
 * Total Accepted:    173.3K
 * Total Submissions: 272.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * 请将其重新排列后变为：
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
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
  pair<ListNode*, ListNode*> splitList(ListNode* head) {
    ListNode tmp(0, head);
    auto* slow = &tmp;
    auto* fast = slow->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto* res = slow->next;
    slow->next = nullptr;

    return {tmp.next, res};
  }

  ListNode* mergeList(ListNode* l1, ListNode* l2) {
    ListNode tmp;
    auto* cur = &tmp;

    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        cur->next = l2;
        break;
      }

      if (l2 == nullptr) {
        cur->next = l1;
        break;
      }

      std::cout << "L1 Val: " << l1->val << std::endl;
      std::cout << "L2 Val: " << l2->val << std::endl;
      cur->next = l1;
      l1 = l1->next;
      cur = cur->next;

      cur->next = l2;
      l2 = l2->next;
      cur = cur->next;
    }

    return tmp.next;
  }

  ListNode* reverseList(ListNode* l) {
    ListNode* pre = nullptr;
    while (l != nullptr) {
      auto* next = l->next;
      l->next = pre;
      pre = l;
      l = next;
    }

    return pre;
  }

  void reorderList(ListNode* head) {
    auto res = splitList(head);
    head = res.first;
    auto* l2 = res.second;
    l2 = reverseList(l2);

    head = mergeList(head, l2);
  }
};
