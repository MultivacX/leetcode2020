// 743. Network Delay Time

// Runtime: 1428 ms, faster than 8.26% of C++ online submissions for Network Delay Time.
// Memory Usage: 43.6 MB, less than 22.22% of C++ online submissions for Network Delay Time.

class Solution {
    unordered_map<int, unordered_map<int, int>> m;
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> ans(N + 1, INT_MAX);
        ans[0] = 0;
        
        for (const auto& t : times) m[t[0]][t[1]] = t[2];
        
        send(ans, K, 0);
        for (int i = 1; i <= N; ++i) if (ans[i] == INT_MAX) return -1;
        return *max_element(begin(ans), end(ans));
    }
    
    void send(vector<int>& ans, int i, int time) {
        if (ans[i] <= time) return;
        else ans[i] = time;
        
        for (auto& kv : m[i]) 
            send(ans, kv.first, kv.second + time);
    }
};