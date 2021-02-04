// 1746. Maximum Subarray Sum After One Operation
// https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/

// Runtime: 184 ms, faster than 100.00% of C++ online submissions for Maximum Subarray Sum After One Operation.
// Memory Usage: 74.2 MB, less than 100.00% of C++ online submissions for Maximum Subarray Sum After One Operation.
    
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0] * nums[0];
        
        int sum = 0, min_sum = 0;
        vector<int> left(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            sum += nums[i];
            min_sum = min(min_sum, sum);
            left[i] = sum - min_sum;
        }
        
        sum = 0; min_sum = 0;
        vector<int> right(n);
        for (int i = n - 1; i > 0; --i) {
            sum += nums[i];
            min_sum = min(min_sum, sum);
            right[i] = sum - min_sum;
        }
        
        int ans = max(left[n - 2] + nums[n - 1] * nums[n - 1], nums[0] * nums[0] + right[1]);
        for (int i = 1; i + 1 < n; ++i) 
            ans = max(ans, left[i - 1] + nums[i] * nums[i] + right[i + 1]);
        return ans;
    }
};