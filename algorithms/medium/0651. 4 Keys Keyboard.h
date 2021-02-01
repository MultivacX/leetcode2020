// 651. 4 Keys Keyboard
// https://leetcode.com/problems/4-keys-keyboard/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for 4 Keys Keyboard.
// Memory Usage: 6.5 MB, less than 73.75% of C++ online submissions for 4 Keys Keyboard.
    
class Solution {
public:
    int maxA(int N) {
        if (N <= 6) return N;
        
        vector<int> dp(N + 1);
        for (int i = 1; i <= 6; ++i)
            dp[i] = i;
        
        for (int i = 7; i <= N; ++i) {
            dp[i] = i;
            for (int j = i - 2; j > 0; --j) {
                // Ctrl-A @ j
                // Ctrl-C @ j+1
                // Ctrl-V @ j+2
                // printf("[%d]: [%d]:%d * %d \n", i, j - 1, dp[j - 1], (i - j));
                dp[i] = max(dp[i], dp[j - 1] * (i - j));
            }
        }
        return dp[N];
    }
};