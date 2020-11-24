// 887. Super Egg Drop
// https://leetcode.com/problems/super-egg-drop/

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