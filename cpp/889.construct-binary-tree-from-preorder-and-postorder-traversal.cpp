/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 亲密字符串
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (63.67%)
 * Total Accepted:    4.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
    TreeNode* buildSubTree(const vector<int>& pre, int i, int j,
                           const vector<int>& post, int x, int y) {
      if (i > j) {
        return nullptr;
      }

      auto root = new TreeNode(pre[i]);
      if (i == j) {
        return root;
      }

      int midIdx = x;
      for (int k = x; k < y; ++k) {
        if (post[k] == pre[i+1]) {
          midIdx = k;
          break;
        }
      }

      int leftLen = midIdx - x + 1;
      int rightLen = y - midIdx - 1;
      root->left = buildSubTree(pre, i + 1,  i + leftLen, post, x, midIdx);
      root->right = buildSubTree(pre, j - rightLen + 1,  j, post, midIdx + 1, y - 1);

      return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
      return buildSubTree(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
};
