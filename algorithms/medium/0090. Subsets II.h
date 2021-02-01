// 90. Subsets II

// Runtime: 8 ms, faster than 84.15% of C++ online submissions for Subsets II.
// Memory Usage: 9.4 MB, less than 68.18% of C++ online submissions for Subsets II.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        f(nums, 0, subset, ans);
        return ans;
    }
    
    void f(vector<int>& nums, int begin, vector<int>& subset, vector<vector<int>>& ans) {
        ans.push_back(subset);
        for (int i = begin; i < nums.size(); ++i) {
            if (i > begin && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            f(nums, i + 1, subset, ans);
            subset.pop_back();
        }
    }
};