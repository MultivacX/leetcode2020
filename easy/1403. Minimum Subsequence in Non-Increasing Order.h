// 1403. Minimum Subsequence in Non-Increasing Order
// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

// Runtime: 28 ms, faster than 6.20% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
// Memory Usage: 11.1 MB, less than 47.71% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
    
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int sum0 = nums[0];
        int sum1 = accumulate(begin(nums), end(nums), 0) - nums[0];
        vector<int> ans{nums[0]};
        for (int i = 1; i < nums.size() && sum0 <= sum1; ++i) {
            sum0 += nums[i];
            sum1 -= nums[i];
            ans.push_back(nums[i]);
        }
        return ans;
    }
};