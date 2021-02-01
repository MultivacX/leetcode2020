// 690. Employee Importance
// https://leetcode.com/problems/employee-importance/

// Runtime: 32 ms, faster than 96.70% of C++ online submissions for Employee Importance.
// Memory Usage: 14.4 MB, less than 51.91% of C++ online submissions for Employee Importance.

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for (auto* e : employees) m[e->id] = e;
        int ans = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                auto* e = m[q.front()]; q.pop();
                ans += e->importance;
                for (int id : e->subordinates)
                    q.push(id);
            }
        }
        return ans;
    }
};