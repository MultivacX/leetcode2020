// 887. Super Egg Drop
// https://leetcode.com/problems/super-egg-drop/

// Runtime: 216 ms, faster than 23.88% of C++ online submissions for Super Egg Drop.
// Memory Usage: 47.7 MB, less than 7.73% of C++ online submissions for Super Egg Drop.

class Solution {
public:
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
};

// TLE
class Solution {
    vector<vector<int>> memo = vector<vector<int>>(101, vector<int>(10001, 20000));
    
public:
    int superEggDrop(int K, int N) {
        // F:OK F+1:break
        if (N <= 0) return 0;
        if (K <= 0) return 20000;
        if (K == 1) return N;
        if (N == 1) return 1;
        
        if (K > N) K = N;
        if (memo[K][N] < 20000) return memo[K][N];

        int drops = 20000;
        // drop 1 egg at floor X
        for (int X = 1; X <= N; ++X) {
            // X:OK, check [X+1, N] with K eggs
            int a = superEggDrop(K, N - X);
            // X:break, check [1, X-1] with K - 1 eggs
            int b = superEggDrop(K - 1, X - 1);
            drops = min(drops, 1 + max(a, b));
        }
        memo[K][N] = drops;
        return drops;
    }
};