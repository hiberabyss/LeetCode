#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		typedef long long ll;
		int N = nums.size();
		if (k < 1) return false;

		set<ll> window;
		int i = 0;
		for (int j = 0; j < N; ++j) {
			if (j - i > k) {
				window.erase(nums[i]);
				i++;
			}

			// nums[j] - t <= nums[i] <= nums[j] + t
			// window is increase sort
			auto it = window.lower_bound((ll)nums[j] - t);
			if (it != window.end() && abs((ll)nums[j] - *it) <= t) return true;

			window.insert(nums[j]);
		}

		return false;
    }

    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
		int N = nums.size();
		if (k <= 0) return false;
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j+i < N; ++j) {
				if (abs(nums[j+i] - nums[j]) <= t) return true;
			}
		}
		return false;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	{
		vector<int> v_nums = {4,2};
		cout << s.containsNearbyAlmostDuplicate(v_nums, 2, 3) <<endl;
	}
	{
		vector<int> v_nums = {4,2};
		cout << s.containsNearbyAlmostDuplicate(v_nums, 2, 1) <<endl;
	}
	{
		vector<int> v_nums = {-1, -1};
		cout << s.containsNearbyAlmostDuplicate(v_nums, 1, 0) <<endl;
	}
	return 0;
}
