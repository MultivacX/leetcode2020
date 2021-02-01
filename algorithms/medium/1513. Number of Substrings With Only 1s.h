// 1513. Number of Substrings With Only 1s
// https://leetcode.com/problems/number-of-substrings-with-only-1s/

// Runtime: 36 ms, faster than 90.60% of C++ online submissions for Number of Substrings With Only 1s.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Number of Substrings With Only 1s.

class Solution {
public:
    int numSub(string s) {
        const int N = s.length();
        int64_t ans = 0;
        for (int i = -1, j = 0; j < N; ++j) {
            if (s[j] == '1' && i == -1) i = j;
            
            if (i != -1) {
                int64_t n = 0;
                if (s[j] == '0') n = j - i;
                else if (j == N - 1) n = j - i + 1;
                
                if (n > 0) {
                    ans = (ans + (1 + n) * n / 2 % 1000000007) % 1000000007;
                    i = -1;   
                }
            }
        }
        return ans;
    }
};