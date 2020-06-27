/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.08%)
 * Total Accepted:    143.2K
 * Total Submissions: 201.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
public:
    void inorderTraversalWithRes(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inorderTraversalWithRes(root->left, res);
        res.push_back(root->val);
        inorderTraversalWithRes(root->right, res);
    }

    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        inorderTraversalWithRes(root, res);

        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        unordered_set<TreeNode*> visited;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            auto left = cur->left;
            while (left != nullptr && visited.find(left) == visited.end()) {
                s.push(left);
                left = left->left;
            }

            cur = s.top();
            s.pop();
            visited.insert(cur);
            res.push_back(cur->val);

            if (cur->right != nullptr) {
                s.push(cur->right);
            }
        }

        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return inorderTraversal2(root);
    }
};
