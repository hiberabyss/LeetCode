#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canWinNim1(int n) {
		bool res[3] = {false, true, true};
		if (n < 3) return res[n];
		for (int i = 3; i <= n; i++) {
			bool cur = !(res[0] || res[1] || res[2]);
			res[0] = res[1];
			res[1] = res[2];
			res[2] = cur;
		}
		return res[2];
    }

    bool canWinNim(int n) {
		return !(n%4 == 0)
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.canWinNim(1348820612) <<endl;
	return 0;
}
