/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (71.13%)
 * Total Accepted:    71.2K
 * Total Submissions: 100.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    void postorderTraversal1(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        postorderTraversal1(root->left, nums);
        postorderTraversal1(root->right, nums);
        nums.push_back(root->val);
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        postorderTraversal1(root, res);
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> s;
        unordered_set<TreeNode*> visited, pushed;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            if ((cur->left == nullptr && cur->right == nullptr) ||
                (cur->left == nullptr && visited.find(cur->right) != visited.end()) ||
                (cur->right == nullptr && visited.find(cur->left) != visited.end()) ||
                (visited.find(cur->left) != visited.end() &&
                 visited.find(cur->right) != visited.end())) {
                res.push_back(cur->val);
                visited.insert(cur);
                s.pop();
            } else if (cur->left != nullptr && visited.find(cur->left) == visited.end()) {
                s.push(cur->left);
            } else if (cur->right != nullptr && visited.find(cur->right) == visited.end()) {
                s.push(cur->right);
            }
            std::cout << "cur: " << cur->val << std::endl;
        }

        return res;
    }
};
