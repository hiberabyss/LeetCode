/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (78.04%)
 * Total Accepted:    21.4K
 * Total Submissions: 27.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
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

        if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
            return false;
        }

        return true;
    }

    int totalNQueens(int n) {
        if (n <= 1) {
            return n;
        }

        vector<vector<int>> res(1);
        for (int k = 0; k < n; ++k) {
            vector<vector<int>> tmpRes;
            for (auto& v : res) {
                for (int j = 0; j < n; ++j) {
                    bool isValid = true;
                    for (auto p : v) {
                        if (!isValidPosition(n, p, k * n + j)) {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) {
                        auto tmp = v;
                        tmp.push_back(k * n + j);
                        tmpRes.push_back(std::move(tmp));
                    }
                }
            }
            swap(tmpRes, res);
        }

        return res.size();
    }
};
