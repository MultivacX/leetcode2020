// 1136. Parallel Courses
// https://leetcode.com/problems/parallel-courses/

// Runtime: 68 ms, faster than 74.43% of C++ online submissions for Parallel Courses.
// Memory Usage: 28 MB, less than 53.82% of C++ online submissions for Parallel Courses.
    
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> p;
        unordered_map<int, int> indegrees;
        for (const auto& v : relations) {
            p[v[0]].push_back(v[1]);
            ++indegrees[v[1]];
        }
        
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegrees.count(i)) continue;
            q.push(i);
        }
        
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int x = q.front();
                q.pop();
                --N;
                if (p.count(x) == 0) continue;
                for (int y : p[x]) 
                    if (--indegrees[y] == 0)
                        q.push(y);
            }
            ++ans;
        }
        return ans != 0 && N == 0 ? ans : -1;
    }
};