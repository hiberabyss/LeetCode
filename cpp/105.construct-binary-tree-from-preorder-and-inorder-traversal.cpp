/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.95%)
 * Total Accepted:    61.2K
 * Total Submissions: 94.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildSubTree(const vector<int>& preorder, int i, int j,
                           const vector<int>& inorder, int x, int y) {
        if (i > j) {
            return nullptr;
        }

        if (i == j) {
            return new TreeNode(preorder[i]);
        }

        auto rootVal = preorder[i];
        int inIdx = x;
        for (int i = x; i <= y; ++i) {
            if (inorder[i] == rootVal) {
                inIdx = i;
                break;
            }
        }

        int leftLen = inIdx - x;
        int rightLen = y - inIdx;
        auto root = new TreeNode(rootVal);
        root->left = buildSubTree(preorder, i + 1, i + leftLen,
                                  inorder, x, x + leftLen - 1);
        root->right = buildSubTree(preorder, j - rightLen + 1, j,
                                   inorder, inIdx + 1, y);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size() || preorder.empty()) {
            return nullptr;
        }

        int N = preorder.size();
        return buildSubTree(preorder, 0, N-1, inorder, 0, N-1);
    }
};
