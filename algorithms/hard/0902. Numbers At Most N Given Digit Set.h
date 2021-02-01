// 902. Numbers At Most N Given Digit Set
// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

// Runtime: 4 ms, faster than 48.77% of C++ online submissions for Numbers At Most N Given Digit Set.
// Memory Usage: 8.3 MB, less than 96.80% of C++ online submissions for Numbers At Most N Given Digit Set.

class Solution {
    int helper(vector<string>& digits, const string& s) {
        const int M = digits.size();
        const int N = s.length();
        int stk = 0;
        int ans = 0;
        for (int j = 0; j < N; ++j) {
            int i = -1; 
            while (i + 1 < M && digits[i + 1][0] <= s[j]) 
                ++i;
            if (i == -1) break;
            
            if (digits[i][0] == s[j]) ++stk;

            int cnt = digits[i][0] == s[j] ? i : i + 1;
            if (cnt <= 0) continue;
            
            for (int k = j + 1; k < N; ++k) 
                cnt *= M; 
            ans += cnt;
            
            if (digits[i][0] < s[j]) break;
        }
        return ans + (stk == N ? 1 : 0);
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        const int M = digits.size();
        
        string s(to_string(n));
        const int N = s.length();
        
        int ans = 0;
        for (int l = 1, k = M; l < N; ++l, k *= M) 
            ans += k;
        return ans + helper(digits, s);
    }
};