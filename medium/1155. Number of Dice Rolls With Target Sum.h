// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Runtime: 60 ms, faster than 36.54% of C++ online submissions for Number of Dice Rolls With Target Sum.
// Memory Usage: 8.7 MB, less than 6.08% of C++ online submissions for Number of Dice Rolls With Target Sum.

class Solution {
    vector<vector<int>> memo;
    
public:
    int numRollsToTarget(int d, int f, int target) {
        if (d == 0 || target <= 0) return d == target;
        
        if (memo.empty()) memo = vector<vector<int>>(d + 1, vector<int>(target + 1, -1));
        if (memo[d][target] >= 0) return memo[d][target];
        
        int cnt = 0;
        for (int i = 1; i <= f; ++i) 
            cnt = (cnt + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
        memo[d][target] = cnt;
        return cnt;
    }
};