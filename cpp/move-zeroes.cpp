#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int cnt = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) cnt++;
			else if (cnt) {
				nums[i-cnt] = nums[i];
				nums[i] = 0;
			}
		}
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	{
		vector<int> nums = {0, 1, 0, 3, 12};
		s.moveZeroes(nums);
		for (auto i : nums) cout << i << " ";
		cout <<endl;
	}
	return 0;
}
