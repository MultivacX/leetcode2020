// 1573. Number of Ways to Split a String
// https://leetcode.com/problems/number-of-ways-to-split-a-string/

// Runtime: 40 ms, faster than 99.47% of C++ online submissions for Number of Ways to Split a String.
// Memory Usage: 14.2 MB, less than 29.57% of C++ online submissions for Number of Ways to Split a String.

class Solution {
public:
    int numWays(string s) {
        int cnt = 0;
        for (const auto& c : s) cnt += c - '0';
        if (cnt % 3) return false;
        
        const int N = s.length();
        if (cnt == 0) return (int64_t)(N - 1) * (int64_t)(N - 2) / 2 % 1000000007;
        
        cnt /= 3;
        int l = -1;
        int lm = -1;
        int rm = -1;
        int r = -1;
        // [0, l] ... 0 ... [lm, rm] ... 0 ... [r, N)
        // s[l] == s[lm] == s[rm] == s[r] == '1'
        int c = 0;
        for (int i = 0; i < N && r < 0; ++i) {
            if (s[i] == '0') continue;
            
            ++c;
            if (c == cnt) c = 0;
            
            if (l < 0) {
                l = c == 0 ? i : -1;      
            } else if (lm < 0) {
                lm = i;
                rm = c == 0 ? i : -1;
            } else if (rm < 0) {
                rm = c == 0 ? i : -1;    
            } else { 
                r = i;
            }
        }
        
        // cout << l << ", " << lm << ", " << rm << ", " << r << endl;
        
        int ans = 0;
        int64_t lp = lm - l;
        int64_t rp = r - rm;
        return lp * rp % 1000000007;
    }
};