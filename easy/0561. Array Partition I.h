// 561. Array Partition I
// https://leetcode.com/problems/array-partition-i/

// Runtime: 132 ms, faster than 56.67% of C++ online submissions for Array Partition I.
// Memory Usage: 28.6 MB, less than 34.98% of C++ online submissions for Array Partition I.
    
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};