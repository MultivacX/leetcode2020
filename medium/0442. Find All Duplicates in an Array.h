// 442. Find All Duplicates in an Array

// Runtime: 116 ms, faster than 73.54% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 14.8 MB, less than 100.00% of C++ online submissions for Find All Duplicates in an Array.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};