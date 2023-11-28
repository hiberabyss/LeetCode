/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 *
 * https://leetcode.cn/problems/h-index/description/
 *
 * algorithms
 * Medium (44.66%)
 * Total Accepted:    129.3K
 * Total Submissions: 279K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
 * 
 * 根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且每篇论文 至少 被引用 h
 * 次。如果 h 有多种可能的值，h 指数 是其中最大的那个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：citations = [3,0,6,1,5]
 * 输出：3 
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
 * 由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
 * 
 * 示例 2：
 * 
 * 
 * 输入：citations = [1,3,1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == citations.length
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
 * 
 * 
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
      int N = citations.size();
      std::vector<int> cnts(N+1, 0);

      for (auto cit : citations) {
        if (cit >= N) {
          cnts[N]++;
        } else {
          cnts[cit]++;
        }
      }

      int cnt = 0;
      for (int i = N; i >= 0; i--) {
        cnt += cnts[i];
        if (cnt >= i) {
          return i;
        }
      }

      return 0;
    }

    int hIndex2(vector<int>& citations) {
      int N = citations.size();
      int left = 0;
      int right = N;
      while (left < right) {
        int mid = (left + right + 1) / 2;
        int cnt = 0;
        for (auto cit : citations) {
          if (cit >= mid) {
            cnt++;
          }
        }

        if (cnt == mid) {
          return mid;
        }

        if (cnt < mid) {
          right = mid - 1;
        } else {  // cnt will be small when increase left
          left = mid;
        }
      }

      return left;
    }

    int hIndex1(vector<int>& citations) {
      std::sort(citations.begin(), citations.end(), std::greater<int>());
      int N = citations.size();
      int res = 0;
      for (int i = 0; i < N; i++) {
        if (citations[i] >= i+1) {
          res = i+1;
        } else {
          break;
        }
      }

      return res;
    }
};
