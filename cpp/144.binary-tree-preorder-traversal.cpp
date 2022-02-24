/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (68.61%)
 * Total Accepted:    238.9K
 * Total Submissions: 347.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 
 * 
 * 
 * 
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<const TreeNode*> st;
        auto* node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                res.push_back(node->val);
                st.push(node);
                node = node->left;
            }

            node = st.top()->right;
            st.pop();
        }

        return res;
    }

    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<const TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            auto* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right != nullptr) {
                st.push(node->right);
            }

            if (node->left != nullptr) {
                st.push(node->left);
            }
        }

        return res;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        preTraversal(root, res);
        return res;
    }

    void preTraversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        res.push_back(root->val);
        preTraversal(root->left, res);
        preTraversal(root->right, res);
    }
};
