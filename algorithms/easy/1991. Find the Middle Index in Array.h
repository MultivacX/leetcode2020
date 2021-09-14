// 1991. Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array/

// Runtime: 7 ms, faster than 48.29% of C++ online submissions for Find the Middle Index in Array.
// Memory Usage: 12.4 MB, less than 39.79% of C++ online submissions for Find the Middle Index in Array.
    
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, pre = 0; i < nums.size(); ++i) {
            if (pre == sum - pre - nums[i])
                return i;
            pre += nums[i];
        }
        return -1;
    }
};