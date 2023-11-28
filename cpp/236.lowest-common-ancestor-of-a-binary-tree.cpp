/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (70.14%)
 * Total Accepted:    605.2K
 * Total Submissions: 862.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  std::unordered_map<TreeNode*, TreeNode*> to_parent;
  std::unordered_set<TreeNode*> p_visited;
public:
  void traverse(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    if (root->left) {
      to_parent[root->left] = root;
      traverse(root->left);
    }

    if (root->right) {
      to_parent[root->right] = root;
      traverse(root->right);
    }
  }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      traverse(root);
      while (p) {
        p_visited.insert(p);
        p = to_parent[p];
      }

      while (q) {
        if (p_visited.contains(q)) {
          return q;
        }
        q = to_parent[q];
      }

      return nullptr;
    }

    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == nullptr || root == p || root == q) {
        return root;
      }

      auto* left = lowestCommonAncestor1(root->left, p, q);
      auto* right = lowestCommonAncestor1(root->right, p, q);
      if (left && right) {
        return root;
      }

      if (left) {
        return left;
      }

      return right;
    }
};
