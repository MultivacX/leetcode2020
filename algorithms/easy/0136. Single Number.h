// 136. Single Number

// Runtime: 16 ms, faster than 70.94% of C++ online submissions for Single Number.
// Memory Usage: 9.8 MB, less than 69.14% of C++ online submissions for Single Number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) 
            ans ^= nums[i];
        return ans;
    }
};