/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (62.03%)
 * Total Accepted:    110.1K
 * Total Submissions: 177.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        for (auto n : nums) {
            pq.push(n);
        }

        int res = 0;
        for (int i = 0; i < k; ++i) {
            res = pq.top();
            pq.pop();
        }

        return res;
    }

    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }

    void quickSort(vector<int>& nums, int i, int j) {
        if (i >= j) {
            return;
        }
        int pivot = nums[i];
        swap(nums[i], nums[j]);
        int y = i;
        for (int x = i; x < j; ++x) {
            if (nums[x] > pivot) {
                swap(nums[y], nums[x]);
                y++;
            }
        }
        swap(nums[y], nums[j]);

        quickSort(nums, i, y-1);
        quickSort(nums, y+1, j);
    }

    int findKthLargest3(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end(), greater<int>());
        quickSort(nums, 0, nums.size() - 1);
        return nums[k-1];
    }

    int findKthLargest(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int x = i;
            int pivot = nums[i];
            swap(nums[i], nums[j]);
            for (int y = i; y < j; ++y) {
                if (nums[y] < pivot) {
                    swap(nums[y], nums[x]);
                    x++;
                }
            }
            swap(nums[x], nums[j]);
            if (j - x + 1 == k) {
                return nums[x];
            } else if (j - x + 1 > k) {
                i = x + 1;
            } else {
                k -= j - x + 1;
                j = x - 1;
            }

            // std::cout << "k: " << k << ", x:" << x << std::endl;
        }

        return nums[i];
    }
};
