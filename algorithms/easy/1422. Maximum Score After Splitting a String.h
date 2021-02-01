// 1422. Maximum Score After Splitting a String
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Score After Splitting a String.
// Memory Usage: 6.6 MB, less than 56.84% of C++ online submissions for Maximum Score After Splitting a String.

class Solution {
public:
    int maxScore(string s) {
        const int N = s.length();
        
        int ones = 0;
        for (int i = 1; i < N; ++i) ones += s[i] - '0';
        
        int ans = 0;
        int zeros = '1' - s[0];
        for (int i = 1; i < N; ++i) {
            ans = max(ans, zeros + ones);
            zeros += '1' - s[i];
            ones -= s[i] - '0';
        }
        return ans;
    }
};