// 1647. Minimum Deletions to Make Character Frequencies Unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

// Runtime: 64 ms, faster than 85.65% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
// Memory Usage: 17.6 MB, less than 77.71% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.

class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26, 0);
        for (auto a : s) ++c[a - 'a'];
        sort(rbegin(c), rend(c));
        // for (int i : c) cout << i << " "; cout << endl; cout << c[0] << " ";
        int ans = 0;
        for (int i = 1; i < 26; ++i) {
            if (c[i] == 0) break;
            if (c[i] < c[i - 1]) continue;
            int val = c[i - 1] > 0 ? c[i - 1] - 1 : 0;
            ans += c[i] - val;
            c[i] = val;
            // cout << c[i] << " ";
        }
        return ans;
    }
};