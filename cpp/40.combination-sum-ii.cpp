/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.64%)
 * Total Accepted:    450.3K
 * Total Submissions: 755.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */
#include <algorithm>
class Solution {
public:
    void subCombineSum(vector<int>& candidates,
                       int idx,
                       int target,
                       vector<int> cur,
                       vector<vector<int>>& res) {
        if (target == 0) {
            return res.push_back(cur);
        }

        if (target < 0 || idx >= candidates.size()) {
            return;
        }

        // avoid duplicate results
        int next_idx = idx + 1;
        while (next_idx < candidates.size() &&
               candidates[next_idx] == candidates[next_idx - 1]) {
            next_idx++;
        }
        subCombineSum(candidates, next_idx, target, cur, res);

        // Following is Wrong: not possible for [idx = 2, target = 8]
        // if (idx == 0 ||
        //     candidates[idx] != candidates[idx - 1]) {
        //     subCombineSum(candidates, idx + 1, target, cur, res);
        // }

        if (candidates[idx] <= target) {
            cur.push_back(candidates[idx]);
            subCombineSum(candidates, idx + 1, target - candidates[idx], cur, res);
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        std::sort(candidates.begin(), candidates.end());
        subCombineSum(candidates, 0, target, {}, res);

        return res;
    }
};
