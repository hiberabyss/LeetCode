/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.86%)
 * Total Accepted:    37.2K
 * Total Submissions: 53.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或七步，可进可退。（引用自
 * 百度百科 - 皇后 ）
 * 
 * 
 */
class Solution {
public:
    bool isValidPosition(int n, int idx1, int idx2) {
        int x1 = idx1 / n;
        int y1 = idx1 % n;
        int x2 = idx2 / n;
        int y2 = idx2 % n;

        if (x1 == x2 ) {
            return false;
        }

        if (y1 == y2 ) {
            return false;
        }

        if (abs(x1 - x2) == abs(y1 - y2)) {
            return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n <= 0) {
            return res;
        }

        vector<vector<int>> ans(1);

        for (int i = 0; i < n; ++i) {
            vector<vector<int>> tmpAns;
            int N = ans.size();
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < n; ++k) {
                    bool isValid = true;
                    for (auto& idx : ans[j]) {
                        if (!isValidPosition(n, i * n + k, idx)) {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) {
                        auto tmp = ans[j];
                        tmp.push_back(i * n + k);
                        tmpAns.push_back(std::move(tmp));
                    }
                }
            }

            swap(tmpAns, ans);
        }

        for (auto& v : ans) {
            vector<string> tmp(n, string(n, '.'));
            for (auto idx : v) {
                int x = idx / n;
                int y = idx % n;
                tmp[x][y] = 'Q';
            }

            res.push_back(std::move(tmp));
        }

        return res;
    }
};
