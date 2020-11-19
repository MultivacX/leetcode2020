// 1653. Minimum Deletions to Make String Balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

// Runtime: 140 ms, faster than 68.84% of C++ online submissions for Minimum Deletions to Make String Balanced.
// Memory Usage: 22.4 MB, less than 79.78% of C++ online submissions for Minimum Deletions to Make String Balanced.

class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.length();
        int ans = N;
        int a_cnt = 0;
        for (char a : s) if (a == 'a') ++a_cnt; 
        for (int i = 0, del_b_before_i = 0; i <= N; ++i) {
            // a[0, i), b[i, N)
            // a_cnt : delete a in [i, N)
            ans = min(ans, del_b_before_i + a_cnt);
            if (i == N) continue;
            if (s[i] == 'b') ++del_b_before_i;
            else --a_cnt;
        }
        return ans;
    }
};