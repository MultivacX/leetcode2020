// 787. Cheapest Flights Within K Stops

// Runtime: 68 ms, faster than 29.58% of C++ online submissions for Cheapest Flights Within K Stops.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Cheapest Flights Within K Stops.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        if (flights.empty()) return -1;
        
        // {u, {v, w}}
        unordered_map<int, unordered_map<int, int>> _flights;
        for (const auto& f : flights) 
            _flights[f[0]][f[1]] = f[2];
        vector<bool> visited(n, false);
        int64_t ans = (int64_t)INT_MAX + 1;
        find(_flights, visited, src, dst, K + 1, 0, ans);
        return ans == (int64_t)INT_MAX + 1 ? - 1 : ans;
    }
    
    void find(unordered_map<int, unordered_map<int, int>>& flights, vector<bool>& visited, int src, int dst, int K, int64_t price, int64_t& ans) {
        if (src == dst) {
            ans = min(ans, price);
            return;
        }
        if (K <= 0) return;
        if (price >= ans) return;
        if (visited[src]) return;
        if (!flights.count(src)) return;
        
        visited[src] = true;
        for (auto& vw : flights[src]) {
            // printf("  u:%d => v:%d, w:%d\n", src, vw.first, vw.second);
            find(flights, visited, vw.first, dst, K - 1, price + vw.second, ans);
        }
        visited[src] = false;
    }
};