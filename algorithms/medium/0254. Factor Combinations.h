// 254. Factor Combinations
// https://leetcode.com/problems/factor-combinations/

// Runtime: 28 ms, faster than 49.80% of C++ online submissions for Factor Combinations.
// Memory Usage: 7 MB, less than 75.30% of C++ online submissions for Factor Combinations.
    
class Solution {
    vector<vector<int>> ans;
    
    void getFactors(int n, vector<int>& v) {
        int i = v.empty() ? 2 : v.back();
        if (i > n) return;
        
        if (!v.empty()) {
            v.push_back(n);
            ans.push_back(v);
            v.pop_back();
        }
        
        for (; i <= n; ++i) {
            int j = n / i;
            if (i * j != n) continue;
            if (i > j) break;
            v.push_back(i);
            getFactors(j, v);
            v.pop_back();
        }
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 3) return {};
        
        vector<int> v;
        getFactors(n, v);
        return ans;
    }
};