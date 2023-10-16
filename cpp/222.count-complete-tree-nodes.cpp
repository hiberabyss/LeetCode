/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (81.08%)
 * Total Accepted:    323.5K
 * Total Submissions: 399K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0 
 * 题目数据保证输入的树是 完全二叉树
 * 
 * 
 * 
 * 
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool searchKinTree(TreeNode* root, int k, int level) {
    // only for tree has at least 2 levels
    for (int i = level - 2; i >= 0; i--) {
      int mask = 1 << i;
      if (mask & k) {
        root = root->right;
      } else {
        root = root->left;
      }
    }

    return root != nullptr;
  }

    int countNodes(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int level = 0;
      auto* node = root;
      while (node != nullptr) {
        node = node->left;
        level++;
      }

      if (level < 2) {
        return 1;
      }

      int min_k = 0;
      int max_k = (1 << (level - 1)) - 1;

      while (min_k < max_k) {
        int mid = (min_k + max_k + 1) / 2;
        if (searchKinTree(root, mid, level)) {
          min_k = mid;
        } else {
          max_k = mid - 1;
        }
      }

      return ((1 << (level - 1)) - 1) + min_k + 1;
    }
};
