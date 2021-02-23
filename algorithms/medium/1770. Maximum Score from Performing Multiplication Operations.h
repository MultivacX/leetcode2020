// 1770. Maximum Score from Performing Multiplication Operations
// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

// Runtime: 484 ms, faster than 33.33% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
// Memory Usage: 173 MB, less than 100.00% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
    
class Solution {
    int helper(const vector<int>& nums, const vector<int>& multipliers, 
               vector<vector<int>>& memo, int i, int k) {
        const int m = multipliers.size();
        if (k >= m) return 0;
        
        const int n = nums.size();
        int j = i + n - 1 - k;
        if (memo[i][k] != INT_MIN) return memo[i][k];
        
        int ans = 0;
        ans = max(nums[i] * multipliers[k] + helper(nums, multipliers, memo, i + 1, k + 1), 
                  nums[j] * multipliers[k] + helper(nums, multipliers, memo, i, k + 1));
        return memo[i][k] = ans;
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int m = multipliers.size();
        vector<vector<int>> memo(m, vector<int>(m, INT_MIN));
        return helper(nums, multipliers, memo, 0, 0);
    }
};

// TLE
// 33 / 59 test cases passed.
class Solution {
    int helper(const vector<int>& nums, const vector<int>& multipliers, vector<vector<int>>& memo, int i, int j) {
        const int n = nums.size();
        const int m = multipliers.size();
        int k = i + n - 1 - j;
        if (k < 0 || k >= m) return 0;
        if (memo[i][j] != INT_MIN) return memo[i][j];
        
        int ans = 0;
        ans = max(nums[i] * multipliers[k] + helper(nums, multipliers, memo, i + 1, j), 
                  nums[j] * multipliers[k] + helper(nums, multipliers, memo, i, j - 1));
        return memo[i][j] = ans;
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int n = nums.size();
        const int m = multipliers.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return helper(nums, multipliers, memo, 0, n - 1);
    }
};