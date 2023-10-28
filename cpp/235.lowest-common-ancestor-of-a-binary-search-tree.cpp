/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (68.83%)
 * Total Accepted:    371.8K
 * Total Submissions: 539.8K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6 
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
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
  std::vector<TreeNode*> p_path;
  std::vector<TreeNode*> q_path;

public:
  void preTraverse(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    if (root->left != nullptr) {
      to_parent[root->left] = root;
      preTraverse(root->left);
    }

    if (root->right != nullptr) {
      to_parent[root->right] = root;
      preTraverse(root->right);
    }
  }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (p->val > q->val) {
        swap(p, q);
      }

      if (p->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
      }

      if (q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
      }

      return root;
    }

    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
      preTraverse(root);
      to_parent[root] = nullptr;

      while (to_parent.contains(p)) {
        p_path.push_back(p);
        p = to_parent[p];
      }

      while (to_parent.contains(q)) {
        q_path.push_back(q);
        q = to_parent[q];
      }

      if (p_path.empty() || q_path.empty()) {
        return nullptr;
      }

      int i = p_path.size() - 1;
      int j = q_path.size() - 1;
      while (i >= 0 && j >= 0 && p_path[i] == q_path[j]) {
        i--; j--;
      }

      return p_path[i+1];
    }
};
