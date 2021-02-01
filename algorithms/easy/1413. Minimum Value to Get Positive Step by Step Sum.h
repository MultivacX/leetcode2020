// 1413. Minimum Value to Get Positive Step by Step Sum
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
// Memory Usage: 7.7 MB, less than 25.61% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
    
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum < 0 && ans > sum) ans = sum;
        }
        return ans > 0 ? 1 : 1 - ans;
    }
};