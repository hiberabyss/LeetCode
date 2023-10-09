/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 *
 * https://leetcode.cn/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (81.62%)
 * Total Accepted:    120.1K
 * Total Submissions: 147.1K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n' +
  '[[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]'
 *
 * 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
 * 
 * 
 * 
 * BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root
 * 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
 * boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
 * int next()将指针向右移动，然后返回指针处的数字。
 * 
 * 
 * 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
 * 
 * 
 * 
 * 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next",
 * "hasNext", "next", "hasNext"]
 * [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
 * 输出
 * [null, 3, 7, true, 9, true, 15, true, 20, false]
 * 
 * 解释
 * BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
 * bSTIterator.next();    // 返回 3
 * bSTIterator.next();    // 返回 7
 * bSTIterator.hasNext(); // 返回 True
 * bSTIterator.next();    // 返回 9
 * bSTIterator.hasNext(); // 返回 True
 * bSTIterator.next();    // 返回 15
 * bSTIterator.hasNext(); // 返回 True
 * bSTIterator.next();    // 返回 20
 * bSTIterator.hasNext(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 10^5] 内
 * 0 
 * 最多调用 10^5 次 hasNext 和 next 操作
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以设计一个满足下述条件的解决方案吗？next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h
 * 是树的高度。
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
class BSTIterator {
  TreeNode* cur_ = nullptr;
  std::unordered_map<TreeNode*, TreeNode*> next_node_map_;
  vector<TreeNode*> nodes_;

public:
  void FillMidTraverseNodes(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    FillMidTraverseNodes(root->left);
    nodes_.push_back(root);
    FillMidTraverseNodes(root->right);
  }

    BSTIterator(TreeNode* root) {
      FillMidTraverseNodes(root);

      int N = nodes_.size();
      for (size_t i = 0; i < nodes_.size(); ++i) {
        if (i == 0) {
          next_node_map_[nullptr] = nodes_[i];
        }

        auto* node = nodes_[i];
        if (i+1 < N) {
          next_node_map_[node] = nodes_[i+1];
        }
      }
    }
    
    int next() {
      cur_ = next_node_map_.at(cur_);
      return cur_->val;
    }
    
    bool hasNext() {
      return next_node_map_.contains(cur_);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */