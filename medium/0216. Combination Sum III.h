// 216. Combination Sum III

// Runtime: 4 ms, faster than 62.96% of C++ online submissions for Combination Sum III.
// Memory Usage: 8.6 MB, less than 97.22% of C++ online submissions for Combination Sum III.

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k < 1 || k > 9 || n < (1 + k) * k / 2 || n > (9 + (9 - k + 1)) * k / 2) return {};
        
        vector<vector<int>> ans;
        vector<int> v;
        dfs(k, n, 1, v, ans);
        return ans;
    }
    
    void dfs(int count, int target, int num, vector<int>& v, vector<vector<int>>& ans) {
        if (count == 0 && target == 0) {
            ans.push_back(v);
            return;
        }
        
        for (int i = num; i <= 9 && count > 0; ++i) {
            if (num > target) break;
            v.push_back(i);
            dfs(count - 1, target - i, i + 1, v, ans);
            v.pop_back();
        }
    }
};