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


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int m = tasks.size();
        if (n == 0) return m;
        
        vector<int> cnts(128);
        for (char c : tasks) ++cnts[c];
        
        int max_cnt = *max_element(begin(cnts), end(cnts));
        if (max_cnt == 1) return m;
        
        int k = 0;
        int others = 0;
        for (int cnt : cnts) 
            if (cnt == max_cnt) ++k;
            else others += cnt;
        int without_last_row = (max_cnt - 1) * (n + 1);
        int last_row = k + max(0, others - (without_last_row - (max_cnt - 1) * k));
        return without_last_row + last_row;
    }
};