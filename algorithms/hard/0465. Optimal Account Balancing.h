// 465. Optimal Account Balancing
// https://leetcode.com/problems/optimal-account-balancing/

// Runtime: 24 ms, faster than 76.34% of C++ online submissions for Optimal Account Balancing.
// Memory Usage: 7 MB, less than 70.04% of C++ online submissions for Optimal Account Balancing.
    
class Solution {
    vector<int64_t> accounts;
    
    int dfs(int i) {
        while (i < accounts.size() && accounts[i] == 0)
            ++i;
        
        int ans = INT_MAX;
        for (int j = i + 1, prev = 0; j < accounts.size(); ++j) {
            int next = accounts[j];
            if (prev != next && accounts[i] * next < 0) {
                accounts[j] = next + accounts[i];
                ans = min(ans, 1 + dfs(i + 1));
                prev = next;
                accounts[j] = next;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int64_t> m;
        for (const auto& t : transactions) 
            m[t[0]] += t[2],
            m[t[1]] -= t[2];
        
        for (const auto& [k, v] : m)
            if (v != 0)
                accounts.push_back(v);
        
        return dfs(0);
    }
};