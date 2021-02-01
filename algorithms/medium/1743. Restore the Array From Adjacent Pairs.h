// 1743. Restore the Array From Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

// Runtime: 556 ms, faster than 40.00% of C++ online submissions for Restore the Array From Adjacent Pairs.
// Memory Usage: 104.1 MB, less than 80.00% of C++ online submissions for Restore the Array From Adjacent Pairs.
    
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int n = adjacentPairs.size() + 1;
        vector<int> nums(n, INT_MAX);
        unordered_map<int, vector<int>> g;
        for (const auto& p : adjacentPairs) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        auto visit = [&](int num){
            for (int nxt : g[num]) 
                for (int& v : g[nxt]) 
                    if (v == num) v = INT_MAX;
        };
        for (const auto& it : g) {
            if (it.second.size() == 1) {
                if (nums[0] == INT_MAX) {
                    nums[0] = it.first;
                    visit(nums[0]);
                } else if (nums[n - 1] == INT_MAX) {
                    nums[n - 1] = it.first;
                    visit(nums[n - 1]);
                }
            }
            if (nums.back() != INT_MAX) break;
        }
        
        for (int i = 1; i < n - 1; ++i) {
            int pre = nums[i - 1];
            for (int cur : g[pre]) {
                if (cur != INT_MAX) {
                    nums[i] = cur;
                    visit(cur);
                    break;
                }
            }
        }
        return nums;
    }
};