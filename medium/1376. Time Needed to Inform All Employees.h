// 1376. Time Needed to Inform All Employees
// https://leetcode.com/problems/time-needed-to-inform-all-employees/

// Runtime: 504 ms, faster than 66.15% of C++ online submissions for Time Needed to Inform All Employees.
// Memory Usage: 127.4 MB, less than 40.05% of C++ online submissions for Time Needed to Inform All Employees.
    
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> employees(n);
        for (int i = 0; i < n; ++i) {
            int m = manager[i];
            if (m >= 0) employees[m].push_back(i);
        }
        
        int ans = 0;
        queue<pair<int, int>> q; q.push({headID, 0});
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int m = q.front().first; 
                int minutes = q.front().second + informTime[m];
                q.pop();
                
                for (int e : employees[m])
                    q.push({e, minutes});
                if (ans < minutes) 
                    ans = minutes;
                // cout << m << ":" << minutes << " ";
            }
            // cout << endl;
        }
        return ans;
    }
};