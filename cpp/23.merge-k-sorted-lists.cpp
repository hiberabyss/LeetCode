/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (50.01%)
 * Total Accepted:    117.1K
 * Total Submissions: 227.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tmpNode;
        ListNode* pre = &tmpNode;

        while (l1 != nullptr || l2 != nullptr) {
            if (l2 == nullptr || (l1 != nullptr && l1->val < l2->val)) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }

        pre->next = nullptr;
        return tmpNode.next;
    }

    ListNode* mergeHelper(vector<ListNode*>& lists, int i, int j) {
        if (i > j) {
            return nullptr;
        }

        if (i == j) {
            return lists[i];
        }

        auto mid = (i + j) / 2;
        auto l1 = mergeHelper(lists, i, mid);
        auto l2 = mergeHelper(lists, mid + 1, j);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeHelper(lists, 0, lists.size() - 1);
    }
};
