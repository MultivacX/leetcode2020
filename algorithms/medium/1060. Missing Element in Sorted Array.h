// 1060. Missing Element in Sorted Array
// https://leetcode.com/problems/missing-element-in-sorted-array/

// Runtime: 104 ms, faster than 37.14% of C++ online submissions for Missing Element in Sorted Array.
// Memory Usage: 31.6 MB, less than 93.78% of C++ online submissions for Missing Element in Sorted Array.
    
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int i = 0;
        while (k > 0) {
            // nums[i] ... nums[j-1] ... nums[i]+k ... nums[j]
            auto it = upper_bound(begin(nums), end(nums), nums[i] + k);
            int j = it - begin(nums);
            int j_1 = j - 1;
            
            // missing numbers in [i, j]
            int cnt = j_1 - i - 1;
            int missing = cnt >= 0 ? nums[j - 1] - nums[i] - 1 - cnt : 0;
            if (missing < 0) missing = 0;
            i = j_1;
            k -= missing;
            
            if (j == nums.size() || nums[j_1] + k < nums[j])
                return nums[j_1] + k;
        }
        return -1;
    }
};