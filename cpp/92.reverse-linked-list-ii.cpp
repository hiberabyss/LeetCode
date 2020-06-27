/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.73%)
 * Total Accepted:    45.7K
 * Total Submissions: 91.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m > n) {
            return nullptr;
        }

        ListNode tmpNode(0);
        tmpNode.next = head;
        ListNode* mPre = &tmpNode, * mNode = nullptr, * nNode = nullptr, * nNodeNext = nullptr;
        for (int i = 1; i < m; ++i) {
            mPre = mPre->next;
        }
        mNode = mPre->next;

        nNode = mNode;
        nNodeNext = nNode->next;
        for (int i = m; i < n; ++i) {
            auto tmp = nNodeNext->next;
            nNodeNext->next = nNode;
            nNode = nNodeNext;
            nNodeNext = tmp;
        }
        mNode->next = nNodeNext;
        mPre->next = nNode;

        return tmpNode.next;
    }
};
