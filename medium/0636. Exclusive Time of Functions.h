// 636. Exclusive Time of Functions
// https://leetcode.com/problems/exclusive-time-of-functions/

// Runtime: 24 ms, faster than 95.93% of C++ online submissions for Exclusive Time of Functions.
// Memory Usage: 13.4 MB, less than 11.39% of C++ online submissions for Exclusive Time of Functions.

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0, pre_id = -1, pre_start = -1, pre_time = -1; i < logs.size(); ++i) {
            int j = logs[i].find(':');
            int k = logs[i].find(':', j + 1);
            
            int id = stoi(logs[i].substr(0, j));
            int start = logs[i][j + 1] == 's' ? 1 : 0;
            int time = stoi(logs[i].substr(k + 1));
                        
            if (i > 0) {
                if (pre_start) ans[pre_id] += time - pre_time;
                if (!start) ans[id] += 1;
                
                // pre_end ... cur_start
                if (!pre_start && start && !s.empty()) 
                    ans[s.top()] += time - pre_time - 1;
                
                // pre_end ... cur_end
                if (!pre_start && !start)
                    ans[id] += time - pre_time - 1;
            }
            
            if (start) s.push(id);
            else s.pop();
            pre_id = id;
            pre_start = start;
            pre_time = time;
        }
        return ans;
    }
};