// 621. Task Scheduler

// Runtime: 296 ms, faster than 20.56% of C++ online submissions for Task Scheduler.
// Memory Usage: 44 MB, less than 6.38% of C++ online submissions for Task Scheduler.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {        
        vector<int> v(26, 0);
        for (const char& t : tasks) ++v[t - 'A'];
        priority_queue<int> q;
        for (int i : v) if (i > 0) q.push(i);
        
        int cnt = 0;
        while (!q.empty()) {
            vector<int> tasks_;
            for (int i = 0; i <= n && !q.empty(); ++i) {
                tasks_.push_back(q.top());
                q.pop();
            }
            for (int i : tasks_) if (i > 1) q.push(i - 1);
            if (!q.empty()) {
                cnt += n + 1;
            } else {
                cnt += tasks_.size();
            }
        }
        return cnt;
    }
};