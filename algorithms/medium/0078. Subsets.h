// 78. Subsets

// Runtime: 8 ms, faster than 60.67% of C++ online submissions for Subsets.
// Memory Usage: 9.1 MB, less than 88.14% of C++ online submissions for Subsets.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        f(nums, 0, subset, ans);
        return ans;
    }
    
    void f(vector<int>& nums, int begin, vector<int>& subset, vector<vector<int>>& ans) {
        ans.push_back(subset);
        for (int i = begin; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            f(nums, i + 1, subset, ans);
            subset.pop_back();
        }
    }
};