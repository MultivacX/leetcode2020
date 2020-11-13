// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Runtime: 104 ms, faster than 50.28% of C++ online submissions for Find All Numbers Disappeared in an Array.
// Memory Usage: 34.2 MB, less than 37.47% of C++ online submissions for Find All Numbers Disappeared in an Array.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i : nums) {
            int idx = abs(i) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};