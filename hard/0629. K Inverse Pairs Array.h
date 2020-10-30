// 629. K Inverse Pairs Array
// https://leetcode.com/problems/k-inverse-pairs-array/submissions/

// Runtime: 44 ms, faster than 34.57% of C++ online submissions for K Inverse Pairs Array.
// Memory Usage: 16.1 MB, less than 9.26% of C++ online submissions for K Inverse Pairs Array.

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;
        
        vector<int> dp(k + 1, 0);
        for (int i = 1; i <= n; ++i) {
            vector<int> prefix(k + 1, 0);
            prefix[0] = 1;
            for (int j = 1; j <= k; ++j)
                prefix[j] = (prefix[j - 1] + dp[j]) % 1000000007;
            
            int m = min(k, (i - 1) * i / 2);
            for (int j = 1; j <= m; ++j) {
                int x = max(0, j - (i - 1)) - 1;
                dp[j] = (prefix[j] - (x >= 0 ? prefix[x] : 0) + 1000000007) % 1000000007;
            }
        }
        return dp[k];
    }
};

// Runtime: 56 ms, faster than 24.38% of C++ online submissions for K Inverse Pairs Array.
// Memory Usage: 44.1 MB, less than 9.26% of C++ online submissions for K Inverse Pairs Array.

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 0));
        
        for (int i = 1; i <= n; ++i) dp[i][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            vector<int64_t> prefix(k + 1, 0);
            prefix[0] = dp[i - 1][0];
            for (int j = 1; j <= k; ++j)
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % 1000000007;
            
            for (int j = 1; j <= k && j <= (i - 1) * i / 2; ++j) {
                /*for (int x = max(0, j - (i - 1)); x <= j; ++x) {
                    // insert number i before position x
                    // then get j - x inverse pairs
                    dp[i][j] += dp[i - 1][x];
                    dp[i][j] %= 1000000007;
                }*/
                int x = max(0, j - (i - 1)) - 1;
                dp[i][j] = (prefix[j] - (x >= 0 ? prefix[x] : 0) + 1000000007) % 1000000007;
            }
        }
        return dp[n][k];
    }
};

// Time Limit Exceeded
// 35 / 80 test cases passed.
class Solution {
    // {n, {k, pairs}}
    unordered_map<int, unordered_map<int, int>> m;
public:
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;
        if (n == 0) return 0;
        
        if (m.count(n) && m[n].count(k)) return m[n][k];
        
        // insert a[n] into array {a[1], ..., a[n-1]}
        // you can get [0, n-1] inverse pairs
        // f(n, k) = sum(f(n-1, i)) and k = i + [0, n-1]
        // k-(n-1) <= i <= k
        int ans = 0;
        for (int i = max(0, k - (n - 1)); i <= k; ++i)
            ans = (ans + kInversePairs(n - 1, i)) % 1000000007;
        m[n][k] = ans;
        return ans;
    }
};