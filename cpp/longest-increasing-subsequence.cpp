#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		size_t N = nums.size();
		if (N < 1) return 0;
		vector<int> dp(N+1, 1);
		dp[0] = 0;

		int res = 1;
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) dp[i+1] = max(dp[i+1], dp[j+1]+1);
			}
			res = max(res, dp[i+1]);
		}

		return res;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	{
		vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
		cout << s.lengthOfLIS(nums) << endl;
	}
	{
		vector<int> nums = {10,9,2,5,3,4};
		cout << s.lengthOfLIS(nums) << endl;
	}
	return 0;
}
