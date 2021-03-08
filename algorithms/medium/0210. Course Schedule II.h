// 210. Course Schedule II

// Runtime: 88 ms, faster than 5.15% of C++ online submissions for Course Schedule II.
// Memory Usage: 15.5 MB, less than 51.72% of C++ online submissions for Course Schedule II.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) return {};
        
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        vector<int> degree(numCourses, 0);
        for (const vector<int>& v : prerequisites) {
            graph[v[1]][v[0]] = true;
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
                
                for (int i = 0; i < numCourses; ++i) {
                    if (!graph[course][i]) continue;
                    --degree[i];
                    if (degree[i] != 0) continue;
                    q.push_back(i);
                    order.push_back(i);
                }
            }
        }
        return order.size() == numCourses ? order : vector<int>();
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> courses(numCourses);
        vector<int> ins(numCourses);
        for (const auto& p : prerequisites) {
            courses[p[1]].insert(p[0]);
            ++ins[p[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (ins[i] == 0) q.push(i);
        
        vector<int> ans;
        while (!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                int i = q.front(); q.pop();
                ans.push_back(i);
                for (int j : courses[i]) 
                    if (--ins[j] == 0)
                        q.push(j);
                courses[i].clear();
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};