/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (71.15%)
 * Total Accepted:    400.3K
 * Total Submissions: 562.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        auto* p1 = head;
        auto* p2 = head->next;

        head->next = nullptr;
        while (p1 != nullptr && p2 != nullptr) {
            auto* p2Next = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2Next;
        }

        return p1;
    }

    // ListNode* reverseList1(ListNode* head) {

    // }
};
