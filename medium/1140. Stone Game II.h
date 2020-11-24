// 1140. Stone Game II
// https://leetcode.com/problems/stone-game-ii/

// Runtime: 24 ms, faster than 39.01% of C++ online submissions for Stone Game II.
// Memory Usage: 10.4 MB, less than 22.11% of C++ online submissions for Stone Game II.
    
class Solution {
    int take(const vector<int>& presum, int start, int M, vector<vector<int>>& memo) {
        const int N = presum.size();
        int pre = start > 0 ? presum[start - 1] : 0;
        if (start + 2 * M >= N) return presum[N - 1] - pre;
        
        if (memo[start][min(M, N)] > 0) return memo[start][min(M, N)];
        
        int ans = 0;
        for (int i = start, X = 1, stones = 0, left = 0; i < N && X <= 2 * M; ++i, ++X) {
            // [start, i]
            stones = presum[i] - pre;
            // [i+1, N-1]
            left = presum[N - 1] - presum[i];
            ans = max(ans, stones + left - take(presum, i + 1, max(M, X), memo));
        }
        memo[start][min(M, N)] = ans;
        return ans;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();
        vector<int> presum(piles);
        for (int i = 1; i < N; ++i) 
            presum[i] = presum[i - 1] + piles[i];
        vector<vector<int>> memo(N, vector<int>(N, 0));
        return take(presum, 0, 1, memo);
    }
};