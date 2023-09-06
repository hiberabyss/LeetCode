/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.55%)
 * Total Accepted:    316.4K
 * Total Submissions: 549K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -100 <= Node.val <= 100
 * 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (root == nullptr) {
        return res;
      }

      stack<TreeNode*> nodes;
      nodes.push(root);
      int level = 0;

      while (!nodes.empty()) {
        stack<TreeNode*> next;
        vector<int> vals;
        while (!nodes.empty()) {
          auto* cur = nodes.top();
          nodes.pop();
          vals.push_back(cur->val);

          if (cur->left == nullptr && cur->right == nullptr) {
            continue;
          }

          if (cur->left != nullptr && cur->right != nullptr) {
            if (level % 2) {
              next.push(cur->right);
              next.push(cur->left);
            } else {
              next.push(cur->left);
              next.push(cur->right);
            }
            continue;
          }

          if (cur->left != nullptr) {
            next.push(cur->left);
          }

          if (cur->right != nullptr) {
            next.push(cur->right);
          }
        }

        res.push_back(vals);
        swap(nodes, next);

        level++;
      }

      return res;
    }
};
