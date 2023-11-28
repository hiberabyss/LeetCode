/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (72.11%)
 * Total Accepted:    92.3K
 * Total Submissions: 128K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j])
 * 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出：16 
 * 解释：这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出：4 
 * 解释：这两个单词为 "ab", "cd"。
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["a","aa","aaa","aaaa"]
 * 输出：0 
 * 解释：不存在这样的两个单词。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] 仅包含小写字母
 * 
 * 
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
      int N = words.size();
      std::vector<int> masks(N, 0);

      for (size_t i = 0; i < N; ++i) {
        for (auto ch : words[i]) {
          masks[i] |= 1 << (ch - 'a');
        }
      }

      int res = 0;
      for (size_t i = 0; i < N; ++i) {
        for (size_t j = i+1; j < N; ++j) {
          if ((masks[i] & masks[j]) == 0) {
            res = max(res, (int)(words[i].size() * words[j].size()));
          }
        }
      }
      return res;
    }
};
