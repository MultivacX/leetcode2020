// 1834. Single-Threaded CPU
// https://leetcode.com/problems/single-threaded-cpu/

// Runtime: 868 ms, faster than 37.68% of C++ online submissions for Single-Threaded CPU.
// Memory Usage: 152.7 MB, less than 34.09% of C++ online submissions for Single-Threaded CPU.
    
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int n = tasks.size();
        for (int i = 0; i < n; ++i)
            tasks[i].push_back(i);
        sort(begin(tasks), end(tasks));
        
        auto cmp = [](vector<int>& l, vector<int>& r) { 
            return l[1] > r[1] || (l[1] == r[1] && l[2] > r[2]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        
        vector<int> ans;
        int i = 0, j = 0; int64_t time = tasks[0][0];
        while (i < n) {
            while (j < n && tasks[j][0] <= time)
                q.push(tasks[j++]);
            if (q.empty()) {
                time = tasks[j][0];
            } else {
                time += q.top()[1];
                ans.push_back(q.top()[2]);
                q.pop();
                ++i;   
            }
        }
        return ans;
    }
};