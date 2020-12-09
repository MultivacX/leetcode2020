// 1470. Shuffle the Array
// https://leetcode.com/problems/shuffle-the-array/

// Runtime: 4 ms, faster than 99.34% of C++ online submissions for Shuffle the Array.
// Memory Usage: 10.1 MB, less than 81.49% of C++ online submissions for Shuffle the Array.
    
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n * 2);
        for (int i = 0, j = 0; i < n * 2; i += 2, ++j) {
            ans[i] = nums[j];
            ans[i + 1] = nums[j + n];
        }
        return ans;
    }
};