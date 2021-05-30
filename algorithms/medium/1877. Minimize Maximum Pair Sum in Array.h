// 1877. Minimize Maximum Pair Sum in Array
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

// Runtime: 236 ms, faster than 25.00% of C++ online submissions for Minimize Maximum Pair Sum in Array.
// Memory Usage: 96.2 MB, less than 50.00% of C++ online submissions for Minimize Maximum Pair Sum in Array.
    
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int n = nums.size();
        int i = 0, j = n - 1;
        int sum = 0;
        while (i < j)
            sum = max(sum, nums[i++] + nums[j--]);
        return sum;
    }
};