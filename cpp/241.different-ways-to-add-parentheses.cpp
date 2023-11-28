/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode.cn/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (75.58%)
 * Total Accepted:    80.3K
 * Total Submissions: 106.2K
 * Testcase Example:  '"2-1-1"'
 *
 * 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
 * 
 * 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10^4 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：expression = "2-1-1"
 * 输出：[0,2]
 * 解释：
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：expression = "2*3-4*5"
 * 输出：[-34,-14,-10,-10,10]
 * 解释：
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= expression.length <= 20
 * expression 由数字和算符 '+'、'-' 和 '*' 组成。
 * 输入表达式中的所有整数值在范围 [0, 99] 
 * 
 * 
 */
class Solution {
  std::vector<int> ops;
  // left, right, res
  std::unordered_map<int, std::unordered_map<int, vector<int>>> dp;

public:
  const vector<int>& dfs(int l, int r) {
    if (!dp[l][r].empty()) {
      return dp[l][r];
    }

    if (l == r) {
      dp[l][r].push_back(ops[l]);
    } else {
      for (int i = l+1; i < r; i += 2) {
        const auto& left = dfs(l, i-1);
        const auto& right = dfs(i+1, r);
        for (auto lv : left) {
          for (auto rv : right) {
            switch (ops[i]) {
              case '+':
                dp[l][r].push_back(lv + rv);
                break;
              case '-':
                dp[l][r].push_back(lv - rv);
                break;
              case '*':
                dp[l][r].push_back(lv * rv);
                break;
            }
          }
        }
      }
    }

    return dp[l][r];
  }

    vector<int> diffWaysToCompute(string expression) {
      int N = expression.size();
      int i = 0;
      while (i < N) {
        if (!isdigit(expression[i])) {
          ops.push_back(expression[i]);
          i++;
        } else {
          int j = i;
          while (j < N && isdigit(expression[j])) {
            j++;
          }

          ops.push_back(std::stol(expression.substr(i, j - i)));

          i = j;
        }
      }

      return dfs(0, ops.size() - 1);
    }
};
