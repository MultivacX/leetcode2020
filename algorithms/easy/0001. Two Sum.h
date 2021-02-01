// 1. Two Sum

// Runtime: 136 ms, faster than 31.68% of C++ online submissions for Two Sum.
// Memory Usage: 9.2 MB, less than 96.19% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) return {i, j};
            }    
        }
        return {};
    }
};