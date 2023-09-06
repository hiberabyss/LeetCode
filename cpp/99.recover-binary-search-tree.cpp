/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode.cn/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.27%)
 * Total Accepted:    139.7K
 * Total Submissions: 231.7K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
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
  vector<TreeNode*> res;
  vector<TreeNode*> midTraverse(TreeNode* root) {
    if (root == nullptr) {
      return res;
    }

    midTraverse(root->left);
    res.push_back(root);
    midTraverse(root->right);

    return res;
  }

    void recoverTree(TreeNode* root) {
      if (root == nullptr) {
        return;
      }
      auto mid_tree = midTraverse(root);

      int first = 0;
      while (first+1 < mid_tree.size() &&
             mid_tree[first]->val <= mid_tree[first+1]->val) {
        first++;
      }

      int second = first+1;
      for (int i = mid_tree.size() - 1; i >= first+1; i--) {
        if (mid_tree[i]->val <= mid_tree[first+1]->val) {
          second = i;
          break;
        }
      }

      swap(mid_tree[first]->val, mid_tree[second]->val);
    }
};
