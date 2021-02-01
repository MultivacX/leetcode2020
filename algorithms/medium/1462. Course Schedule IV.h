// 1462. Course Schedule IV
// https://leetcode.com/problems/course-schedule-iv/

// Runtime: 376 ms, faster than 92.00% of C++ online submissions for Course Schedule IV.
// Memory Usage: 63.5 MB, less than 60.35% of C++ online submissions for Course Schedule IV.

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& e : prerequisites)
            graph[e[0]].push_back(e[1]);
        
        vector<vector<bool>> m(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            m[i][i] = true;
            
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int j = q.front();
                    q.pop();
                    
                    for (int k : graph[j]) {
                        if (m[i][k]) continue;
                        m[i][k] = true;
                        q.push(k);
                    }
                }
            }
        }
        
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i)
            ans[i] = m[queries[i][0]][queries[i][1]];
        return ans;
    }
};