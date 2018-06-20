#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;
        int N = s.size();
        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);

        for (int i = 0; i < N; ++i) {
            smap[s[i]-'a']++;
            tmap[t[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if ( smap[i] != tmap[i] ) return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}

