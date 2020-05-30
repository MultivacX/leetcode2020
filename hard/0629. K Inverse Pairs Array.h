// 629. K Inverse Pairs Array

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