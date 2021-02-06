// 1246. Palindrome Removal
// https://leetcode.com/problems/palindrome-removal/

// Runtime: 84 ms, faster than 90.12% of C++ online submissions for Palindrome Removal.
// Memory Usage: 15.4 MB, less than 81.48% of C++ online submissions for Palindrome Removal.
    
class Solution {
    int dp(const vector<int>& arr, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        
        const int n = arr.size();
        
        // 1. remove arr[i]
        int ans = 1 + dp(arr, i + 1, j, memo);
        
        // 2. remove arr[i] & arr[i+1]
        if (i + 1 < n && arr[i] == arr[i + 1])
            ans = min(ans, 1 + dp(arr, i + 2, j, memo));
        
        // 3.
        for (int k = i + 2; k <= j; ++k)
            if (arr[i] == arr[k])
                ans = min(ans, dp(arr, i + 1, k - 1, memo) + dp(arr, k + 1, j, memo));
        
        memo[i][j] = ans;
        return ans;
    }
    
public:
    int minimumMoves(vector<int>& arr) {
        const int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(arr, 0, n - 1, memo);
    }
};