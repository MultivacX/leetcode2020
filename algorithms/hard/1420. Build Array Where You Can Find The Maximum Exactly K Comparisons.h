// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

// Runtime: 156 ms, faster than 28.90% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.
// Memory Usage: 9.3 MB, less than 26.61% of C++ online submissions for Build Array Where You Can Find The Maximum Exactly K Comparisons.

class Solution {
    int m;
    
    int build(int n, int k, int max_val, vector<vector<vector<int>>>& memo) {
        if (n < 0 || k < 0 || n < k) return 0;
        if (n == 0 && k == 0) return 1;
        if (memo[n][k][max_val + 1] != -1) 
            return memo[n][k][max_val + 1];
        
        int cnt = 0;
        // set arr[N-n] = i
        for (int i = 1; i <= m; ++i)
            cnt = (cnt + build(n - 1, i > max_val ? k - 1 : k, max(i, max_val), memo)) % 1000000007;
        memo[n][k][max_val + 1] = cnt;
        return cnt;
    }
    
public:
    int numOfArrays(int n, int m, int k) {
        this->m = m;
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 2, -1)));
        return build(n, k, -1, memo);
    }
};