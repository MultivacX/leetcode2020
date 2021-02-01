// 825. Friends Of Appropriate Ages

// Runtime: 72 ms, faster than 54.40% of C++ online submissions for Friends Of Appropriate Ages.
// Memory Usage: 29.2 MB, less than 33.33% of C++ online submissions for Friends Of Appropriate Ages.

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        vector<int> m(121, 0);
        for (int a : ages) ++m[a];
        for (int i = 1; i <= 120; ++i) {
            if (m[i] == 0) continue;
            for (int j = 1; j <= 120; ++j) {
                if (m[j] == 0) continue;
                if (2 * j <= i + 14) continue;
                if (j > i) continue;
                if (j > 100 && i < 100) continue;
                // cout << i << "->" << j << endl;
                ans += m[i] * m[j];
                if (i == j) ans -= m[i];
            }
        }
        return ans;
    }
};