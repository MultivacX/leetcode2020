// 1788. Maximize the Beauty of the Garden
// https://leetcode.com/problems/maximize-the-beauty-of-the-garden/

// Runtime: 84 ms, faster than 100.00% of C++ online submissions for Maximize the Beauty of the Garden.
// Memory Usage: 55.6 MB, less than 100.00% of C++ online submissions for Maximize the Beauty of the Garden.
    
class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        const int n = flowers.size();
        int ans = INT_MIN;    
        // leftest flower[i]: {flower[i], max_subseq_sum(0, ..., i-1)}
        unordered_map<int, int> m;
        for (int i = 0, presum = 0; i < n; ++i) {
            int cur = flowers[i];
            if (!m.count(cur)) {
                m.insert({cur, presum});
            } else {
                int val = cur * 2 + presum - m[cur];
                if (cur > 0) val -= cur;
                if (ans < val) ans = val;
            }
            presum += cur > 0 ? cur : 0;
        }
        return ans;
    }
};

// TLE
// 188 / 207 test cases passed.
class Solution {
    int ans = INT_MIN;
    
    vector<vector<int>> memo_beauty;
    vector<vector<bool>> memo_dp;
    
    int beauty(const vector<int>& flowers, int i, int j) {
        if (i > j) return 0;
        if (i == j) return flowers[i] >= 0 ? flowers[i] : 0;
        
        if (memo_beauty[i][j] != INT_MIN) return memo_beauty[i][j];
        
        int val = 0;
        for (int k = i; k <= j; ++k)
            if (flowers[k] > 0)
                val += flowers[k];
        memo_beauty[i][j] = val;
        return val;
    }
    
    void dp(const vector<int>& flowers, int i, int j) {
        if (i >= j) return;
        
        if (memo_dp[i][j]) return;
        
        if (flowers[i] == flowers[j]) {
            int cur = flowers[i] * 2 + beauty(flowers, i + 1, j - 1);
            if (cur > ans) ans = cur;
        } 
        if (i + 1 < flowers.size() && !memo_dp[i + 1][j]) dp(flowers, i + 1, j);
        if (j - 1 >= 0 && !memo_dp[i][j - 1]) dp(flowers, i, j - 1);
        
        memo_dp[i][j] = true;
    }
    
public:
    int maximumBeauty(vector<int>& flowers) {
        const int n = flowers.size();
        memo_beauty = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        memo_dp = vector<vector<bool>>(n, vector<bool>(n, false));
        dp(flowers, 0, n - 1);
        return ans;
    }
};