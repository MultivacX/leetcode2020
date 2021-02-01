// 826. Most Profit Assigning Work

// Runtime: 224 ms, faster than 26.72% of C++ online submissions for Most Profit Assigning Work.
// Memory Usage: 37.7 MB, less than 9.09% of C++ online submissions for Most Profit Assigning Work.

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int M = difficulty.size();
        vector<pair<int, int>> d_p(M);
        for (int i = 0; i < M; ++i) {
            d_p[i].first = difficulty[i];
            d_p[i].second = profit[i];
        }
        sort(begin(d_p), end(d_p));
        
        sort(begin(worker), end(worker));
        
        auto cmp = [&](const int a, const int b){ return d_p[a].second < d_p[b].second; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        
        int ans = 0;
        int i = 0;
        for (int d : worker) {
            while (i < M && d_p[i].first <= d) q.push(i++);
            if (q.empty()) continue;
            ans += d_p[q.top()].second;
        }
        return ans;
    }
};