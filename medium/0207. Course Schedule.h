// 207. Course Schedule

// Runtime: 24 ms, faster than 64.90% of C++ online submissions for Course Schedule.
// Memory Usage: 14.3 MB, less than 45.45% of C++ online submissions for Course Schedule.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0 || prerequisites.empty()) return true;
        
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        vector<int> degree(numCourses, 0);
        for (const vector<int>& v : prerequisites) {
            graph[v[1]].insert(v[0]);
            ++degree[v[0]];
        }
        
        vector<int> order;
        deque<int> q;
        for (int i = 0; i < numCourses; ++i) {
            // printf("%d:%d\n", i, degree[i]);
            if (degree[i] != 0) continue;
            q.push_back(i);
            order.push_back(i);
        }
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                int course = q.front();
                q.pop_front();
                --size;
                
                for (int i : graph[course]) {
                    --degree[i];
                    if (degree[i] != 0) continue;
                    q.push_back(i);
                    order.push_back(i);
                }
            }
        }
        return order.size() == numCourses ? true : false;
    }
};