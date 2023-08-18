/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (70.88%)
 * Total Accepted:    386.1K
 * Total Submissions: 544.7K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
class Solution {
public:
  std::unordered_map<int, std::unordered_map<int, int>> caches;

  int cntTree(int left, int right) {
    if (left > right) {
      return 1;
    }

    if (caches.contains(left) && caches.at(left).contains(right)) {
      return caches.at(left).at(right);
    }

    int res = 0;
    for (size_t i = left; i <= right; ++i) {
      res += cntTree(left, i-1) * cntTree(i+1, right);
    }
    caches[left][right] = res;
    return res;
  }

    int numTrees(int n) {
      return cntTree(1, n);
    }
};
