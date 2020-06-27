/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.81%)
 * Total Accepted:    126.2K
 * Total Submissions: 248.5K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isVecSymmetric(const vector<TreeNode*>& v) {
        int i = 0, j = v.size() - 1;
        while (i < j) {
            if (v[i] == nullptr && v[j] == nullptr) {
                i++; j--;
                continue;
            }
            if (v[i] == nullptr || v[j] == nullptr) {
                return false;
            }

            if (v[i]->val != v[j]->val) {
                return false;
            }
            i++; j--;
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> curLevel;
        auto nextLevel = curLevel;
        curLevel.push_back(root);

        while (!curLevel.empty()) {
            if (!isVecSymmetric(curLevel)) {
                return false;
            }

            bool isEnd = true;

            for (auto& n : curLevel) {
                if (n != nullptr) {
                    isEnd = false;
                    nextLevel.push_back(n->left);
                    nextLevel.push_back(n->right);
                } else {
                    nextLevel.push_back(nullptr);
                    nextLevel.push_back(nullptr);
                }
            }

            if (isEnd) {
                break;
            }

            swap(curLevel, nextLevel);
            nextLevel.clear();
        }

        return true;
    }
};
