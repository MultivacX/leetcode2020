// 1920. Build Array from Permutation
// https://leetcode.com/problems/build-array-from-permutation/

// Runtime: 12 ms, faster than 66.67% of C++ online submissions for Build Array from Permutation.
// Memory Usage: 16.2 MB, less than 33.33% of C++ online submissions for Build Array from Permutation.
    
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int bits = 10;
        const int mask = 1023;
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] = ((nums[nums[i]] & mask) << bits) | (nums[i] & mask);
        for (int i = 0; i < n; ++i)
            nums[i] = nums[i] >> bits;
        return nums;
    }
};