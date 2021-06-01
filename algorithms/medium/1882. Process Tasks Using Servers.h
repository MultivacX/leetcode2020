// 1882. Process Tasks Using Servers
// https://leetcode.com/problems/process-tasks-using-servers/

// Runtime: 560 ms, faster than 75.29% of C++ online submissions for Process Tasks Using Servers.
// Memory Usage: 119.8 MB, less than 86.44% of C++ online submissions for Process Tasks Using Servers.
    
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P = pair<int, int>; 
        // {weight, index}, {end time, index}
        priority_queue<P, vector<P>, greater<P>> idles, runnings;
        for (int i = 0; i < servers.size(); ++i)
            idles.push({servers[i], i});
        
        vector<int> ans(tasks.size());
        int t = 0, sec = 0;
        while (t < tasks.size()) {
            while (!runnings.empty() && runnings.top().first <= sec) {
                int i = runnings.top().second; runnings.pop();
                idles.push({servers[i], i});
            }
            
            if (idles.empty()) {
                sec = runnings.top().first;
            } else {
                while (!idles.empty() && t <= sec && t < tasks.size()) {
                    int i = idles.top().second; idles.pop();
                    runnings.push({sec + tasks[t], i});
                    ans[t++] = i;
                }
                ++sec;
            }
        }
        return ans;
    }
};