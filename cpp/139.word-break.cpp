/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (54.36%)
 * Total Accepted:    477.5K
 * Total Submissions: 878.2K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 * 
 * 
 */
class Solution {
  std::unordered_map<int, bool> cache_res;

public:
    bool wordBreakWithIdx(const string& s, vector<string>& wordDict, int idx) {
      if (idx >= s.size()) {
        return true;
      }

      if (cache_res.contains(idx)) {
        return cache_res.at(idx);
      }

      for (const auto& word : wordDict) {
        if (word.empty()) {
          continue;
        }

        if (s.find(word, idx) == idx &&
            wordBreakWithIdx(s, wordDict, idx + word.size())) {
          cache_res[idx] = true;
          return true;
        }
      }

      cache_res[idx] = false;
      return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
      return wordBreakWithIdx(s, wordDict, 0);
    }
};
