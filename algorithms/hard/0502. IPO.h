// 502. IPO
// https://leetcode.com/problems/ipo/

// Runtime: 140 ms, faster than 84.36% of C++ online submissions for IPO.
// Memory Usage: 23.3 MB, less than 7.06% of C++ online submissions for IPO.

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // Capital[i] <= W && max(Profits[i])
        
        map<int, vector<int>> m;
        priority_queue<int> q;
        for (int i = 0; i < Profits.size(); ++i) {
            if (W < Capital[i]) {
                m[Capital[i]].push_back(Profits[i]);
            } else {
                q.push(Profits[i]);   
            }
        }
        while (k > 0 && !q.empty()) {
            int profit = q.top();
            q.pop();
            W += profit;
            --k;
            
            auto u = m.upper_bound(W);
            for (auto it = m.begin(); it != u; ++it) 
                for (int profit : it->second)
                    q.push(profit);
            m.erase(m.begin(), u);
        }
        return W;
    }
};