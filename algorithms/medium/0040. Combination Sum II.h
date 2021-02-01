// 40. Combination Sum II

// Runtime: 8 ms, faster than 84.10% of C++ online submissions for Combination Sum II.
// Memory Usage: 9 MB, less than 94.74% of C++ online submissions for Combination Sum II.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        dfs(candidates, target, 0, v, ans);
        return ans;
    }
    
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& v, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            v.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, v, ans);
            v.pop_back();
        }
    }
};