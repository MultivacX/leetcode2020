// 1685. Sum of Absolute Differences in a Sorted Array
// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// Runtime: 196 ms, faster than 14.29% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
// Memory Usage: 86 MB, less than 14.29% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
    
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n);
        for (int i = 0; i < n; ++i)
            prefix[i] = nums[i] + (i > 0 ? prefix[i - 1] : 0);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (i + 1) * nums[i] - prefix[i] + 
                prefix[n - 1] - prefix[i] - (n - i - 1) * nums[i]; 
        }
        return ans;
    }
};