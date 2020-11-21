// 1583. Count Unhappy Friends
// https://leetcode.com/problems/count-unhappy-friends/

// Runtime: 252 ms, faster than 31.47% of C++ online submissions for Count Unhappy Friends.
// Memory Usage: 45.8 MB, less than 19.81% of C++ online submissions for Count Unhappy Friends.

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<unordered_map<int, int>> m_preferences(n);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n - 1; ++j) 
                m_preferences[i].insert({preferences[i][j], j});
        
        vector<int> m_pairs(n);
        for (const auto& p : pairs) 
            m_pairs[p[0]] = p[1], m_pairs[p[1]] = p[0];
            
        auto unhappy = [&](int x, int y){
            int x2y = m_preferences[x][y];
            for (int j = 0; j < x2y; ++j) {
                int u = preferences[x][j];
                int v = m_pairs[u];
                int x2u = j;
                int u2x = m_preferences[u][x];
                int u2v = m_preferences[u][v];
                if (x2u < x2y && u2x < u2v) return true;
            }
            return false;
        };

        vector<int> ans(n, 0);
        for (const auto& p : pairs) {
            if (unhappy(p[0], p[1])) ans[p[0]] = 1;
            if (unhappy(p[1], p[0])) ans[p[1]] = 1;
        }
        return accumulate(begin(ans), end(ans), 0);
    }
};