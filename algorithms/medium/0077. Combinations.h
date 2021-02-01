// 77. Combinations

// Runtime: 76 ms, faster than 80.09% of C++ online submissions for Combinations.
// Memory Usage: 11.9 MB, less than 75.00% of C++ online submissions for Combinations.

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k <= n) {
            vector<int> v;
            dfs(n, k, 1, v, ans);
        }
        return ans;
    }
    
    void dfs(int n, int k, int idx, vector<int>& v, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i = idx; i <= n; ++i) {
            v.push_back(i);
            dfs(n, k - 1, i + 1, v, ans);
            v.pop_back();
        }
    }
};