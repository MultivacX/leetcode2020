// 1567. Maximum Length of Subarray With Positive Product
// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

// Runtime: 204 ms, faster than 97.89% of C++ online submissions for Maximum Length of Subarray With Positive Product.
// Memory Usage: 58 MB, less than 63.02% of C++ online submissions for Maximum Length of Subarray With Positive Product.

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        const int N = nums.size();
        int left = -1;
        int left_neg = -1;
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == 0) {
                if (cur > 0) {
                    ans = max(ans, i - left);
                } else if (cur < 0) {
                    ans = max(ans, i - left_neg - 1);
                }
                
                left = -1;
                left_neg = -1;
                cur = 0;
                continue;
            } 
            
            if (nums[i] > 0) {
                if (cur == 0) cur = 1;    
            } else {
                if (left_neg < 0) left_neg = i;
                
                if (cur == 0) cur = -1;
                else cur *= -1;
            }
            
            if (left < 0) left = i;
            if (cur > 0) {
                ans = max(ans, i - left + 1);
            } else if (cur < 0) {
                ans = max(ans, i - left_neg);
            }
        }
        return ans;
    }
};