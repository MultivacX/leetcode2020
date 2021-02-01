// 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/

// Runtime: 244 ms, faster than 78.39% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 78 MB, less than 7.39% of C++ online submissions for Maximum Average Subarray I.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i + 1 >= k) maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};