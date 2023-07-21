/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode.cn/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (45.11%)
 * Total Accepted:    83.7K
 * Total Submissions: 185.7K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 * 
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 +
 * ...
 * 
 * 
 * 注意：a + b 意味着字符串 a 和 b 连接。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s1 = "", s2 = "", s3 = ""
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1、s2、和 s3 都由小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
 * 
 */
class Solution {
public:
  unordered_map<int, bool> caches;

    bool isInterleave(const string& s1, const string& s2, const string& s3,
                      int x, int y , int z) {
      int N = s2.size();
      int idx = x * (N + 1) + y;

      // std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

      if (z == s3.size()) {
        caches[idx] = true;
        return true;
      }

      if (caches.find(idx) != caches.end()) {
        return caches[idx];
      }

      if (x < s1.size() && s1[x] == s3[z] && isInterleave(s1, s2, s3, x+1, y, z + 1)) {
        caches[idx] = true;
        return true;
      }

      if (y < s2.size() && s2[y] == s3[z] && isInterleave(s1, s2, s3, x, y+1, z+1)) {
        caches[idx] = true;
        return true;
      }

      caches[idx] = false;

      return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
      if (s1.size() + s2.size() != s3.size()) {
        return false;
      }

      return isInterleave(s1, s2, s3, 0, 0, 0);
    }
};
