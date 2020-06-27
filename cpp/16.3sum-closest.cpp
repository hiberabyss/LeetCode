/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.80%)
 * Total Accepted:    94K
 * Total Submissions: 214.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest1(vector<int>& nums, int target) {
        int N = nums.size();
        if (N < 3) {
            return 0;
        }

        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                for (int k = j+1; k < N; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs(res - target)) {
                        res = sum;
                    }
                }
            }
        }

        return res;
    }

    int threeSumClosest2(vector<int>& nums, int target) {
        int N = nums.size();
        if (N < 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i + 2 < N; ++i) {
            int start = i + 1;
            int end = N - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) {
                    return sum;
                }

                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }

                if (sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }

        return res;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        return threeSumClosest2(nums, target);
    }
};
