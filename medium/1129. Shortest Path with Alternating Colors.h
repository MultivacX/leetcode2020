// 1129. Shortest Path with Alternating Colors

// Runtime: 80 ms, faster than 11.95% of C++ online submissions for Shortest Path with Alternating Colors.
// Memory Usage: 15.8 MB, less than 100.00% of C++ online submissions for Shortest Path with Alternating Colors.

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ans(n, -1);
        ans[0] = 0;
        
        unordered_map<int, vector<int>> R;
        for (const auto& e : red_edges) R[e[0]].push_back(e[1]);
        
        unordered_map<int, vector<int>> B;
        for (const auto& e : blue_edges) B[e[0]].push_back(e[1]);
        
        int len = 0;
        queue<vector<int>> q;
        q.push({0, 0}); // red
        q.push({1, 0}); // blue
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        visited[0][0] = true;
        visited[1][0] = true;
        while (!q.empty()) {
            ++len;
            int size = q.size();
            while (size-- > 0) {
                int color = q.front()[0];
                int idx = q.front()[1];
                q.pop();
                
                int next_color = ~color & 1;
                vector<int>* next_level = color == 0 ? &B[idx] : &R[idx];
                
                for (int next : *next_level) {
                    if (visited[next_color][next]) continue;
                    visited[next_color][next] = true;
                    if (ans[next] == -1 || ans[next] > len) ans[next] = len;
                    q.push({next_color, next});
                }
            }
        }
        return ans;
    }
};