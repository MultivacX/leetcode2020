// 377. Combination Sum IV

// Runtime: 4 ms, faster than 68.52% of C++ online submissions for Combination Sum IV.
// Memory Usage: 8.6 MB, less than 90.00% of C++ online submissions for Combination Sum IV.

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        /*
		// Runtime Error
		// 12 / 17 test cases passed.
		// Line 10: Char 27: runtime error: signed integer overflow: 357856184 + 1941940377 cannot be represented in type 'int' (solution.cpp)
		// [3,33,333]
		// 10000
        vector<int> dp(target + 1, 0);
        */
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp.back();
    }
};