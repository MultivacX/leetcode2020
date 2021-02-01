// 582. Kill Process
// https://leetcode.com/problems/kill-process/

// Runtime: 256 ms, faster than 36.11% of C++ online submissions for Kill Process.
// Memory Usage: 68.1 MB, less than 39.24% of C++ online submissions for Kill Process.
    
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); ++i) {
            m[ppid[i]].push_back(pid[i]);
        }
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int p = q.front();
                q.pop();
                ans.push_back(p);
                for (int i : m[p])
                    q.push(i);
            }
        }
        return ans;
    }
};