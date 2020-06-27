/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (50.03%)
 * Total Accepted:    94.3K
 * Total Submissions: 188.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode tmpNode(0);
        tmpNode.next = head;
        ListNode* pre = &tmpNode, * cur = pre->next;
        while (cur != nullptr && cur->next != nullptr) {
            while (cur->next != nullptr && cur->val == cur->next->val) {
                cur = cur->next;
            }

            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }

        return tmpNode.next;
    }
};
