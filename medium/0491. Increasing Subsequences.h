// 491. Increasing Subsequences

// Runtime: 268 ms, faster than 31.47% of C++ online submissions for Increasing Subsequences.
// Memory Usage: 22.3 MB, less than 40.00% of C++ online submissions for Increasing Subsequences.

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return {};
        
        set<vector<int>> ans;
        vector<int> subsequence;
        f(nums, 0, subsequence, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void f(const vector<int>& nums, int begin, vector<int>& subsequence, set<vector<int>>& ans) {
        const int n = nums.size();
        if (begin >= n)
            return;
        
        for (int i = begin; i < n; ++i) {
            if (i > begin && nums[i - 1] == nums[i])
                continue;
            bool pushed = subsequence.empty() || subsequence.back() <= nums[i];
            if (pushed) 
                subsequence.push_back(nums[i]);
            if (subsequence.size() > 1)
                ans.insert(subsequence);
            f(nums, i + 1, subsequence, ans);
            if (pushed) 
                subsequence.pop_back();
        }
    }
};

// optim:
// use int masks NOT a set<vector<int>>