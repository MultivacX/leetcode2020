// 47. Permutations II

// Runtime: 24 ms, faster than 73.48% of C++ online submissions for Permutations II.
// Memory Usage: 10.7 MB, less than 33.33% of C++ online submissions for Permutations II.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        f(nums, 0, ans);
        return ans;
    }
    
    void f(vector<int> nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[i])
                continue;
            swap(nums[j], nums[i]);
            f(nums, i + 1, ans);
        }
    }
};