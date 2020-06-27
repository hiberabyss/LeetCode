/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.95%)
 * Total Accepted:    32.9K
 * Total Submissions: 48.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
public:
    TreeNode* buildSubTree(vector<int>& inorder, int i, int j,
                           vector<int>& postorder, int x, int y) {
        if (i > j || x > y) {
            return nullptr;
        }

        auto root = new TreeNode(postorder[y]);
        if (i == j) {
            return root;
        }

        int midIdx = i;
        for (int k = i; k <= j; ++k) {
            if (inorder[k] == root->val) {
                midIdx = k;
                break;
            }
        }

        int leftLen = midIdx - i;
        int rightLen = j - midIdx;
        root->left = buildSubTree(inorder, i, i + leftLen - 1,
                                  postorder, x, x + leftLen - 1);

        root->right = buildSubTree(inorder, j - rightLen + 1, j,
                                  postorder, y - rightLen, y - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.empty()) {
            return nullptr;
        }
        int N = inorder.size();
        return buildSubTree(inorder, 0, N - 1, postorder, 0, N - 1);
    }
};
