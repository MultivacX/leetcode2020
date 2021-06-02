// 1884. Egg Drop With 2 Eggs and N Floors
// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.
    
class Solution {
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        // dp[m][k] = max_floors
        // using m drops & k eggs, we can find F in [1, max_floors] 

        int m = 0;
        while (dp[m][K] < N) {
            ++m;
            for (int k = 1; k <= K; ++k) {
                // dp[m-1][k-1] : [1, f0] 
                // dp[m-1][k]   : [1, f1]
                
                // drop 1 egg at f0+1
                // then taking m-1 moves to
                // if egg broken, using k-1 eggs, can find F in [1, f0] 
                // if not,        using k eggs,   can find F in [f0+1][f0+2, f0+1+f1] 
                
                // dp[m][k]     : [1, f0][f0+1][f0+2, f0+1+f1]
                dp[m][k] = dp[m - 1][k - 1] + 1 + dp[m - 1][k];
            }
        }
        return m;
    }
    
public:
    int twoEggDrop(int n) {
        return superEggDrop(2, n);
    }
};