// 207. Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0 || prerequisites.empty()) return true;
        
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for (const vector<int>& v : prerequisites) {
            g[v[1]].push_back(v[0]);
            ++degree[v[0]];
        }
        
        for (int i = 0; i < numCourses; ++i) {
            vector<int> visited(degree);
            if (isCircle(g, i, visited)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isCircle(const vector<vector<int>>& g, int course, vector<int>& visited) {
        if (visited[course] < 0) return true;
        --visited[course];
        
        for (int next_course : g[course]) {
            if (isCircle(g, next_course, visited)) {
                return true;
            }
        }
        
        return false;
    }
};