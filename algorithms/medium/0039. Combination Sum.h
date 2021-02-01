// 39. Combination Sum

// Runtime: 20 ms, faster than 41.69% of C++ online submissions for Combination Sum.
// Memory Usage: 10 MB, less than 54.17% of C++ online submissions for Combination Sum.

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            vector<int> v;
            f(candidates, target, i, v);
        }
        return ans;
    }
    
    bool f(vector<int>& candidates, int target, int start, vector<int>& v) {
        if (start >= candidates.size() || target < 0) return false;
        if (target == 0) {
            ans.push_back(v);
            return false;
        }
        
        v.push_back(candidates[start]);
        for (int i = start; i < candidates.size(); ++i) {
            if (!f(candidates, target - candidates[start], i, v)) 
                break;
        }
        v.pop_back();
        
        return true;
    }
};