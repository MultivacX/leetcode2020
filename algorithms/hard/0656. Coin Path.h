// 656. Coin Path
// https://leetcode.com/problems/coin-path/

// Runtime: 8 ms, faster than 95.29% of C++ online submissions for Coin Path.
// Memory Usage: 13 MB, less than 61.18% of C++ online submissions for Coin Path.
    
class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        const int n = coins.size();
        
        // {cost, next_node}
        vector<pair<int, int>> distTo(n, {INT_MAX, -1});
        distTo[n - 1].first = 0;
        distTo[n - 1].second = n;
        
        for (int i = n - 1; i >= 0; --i) {
            if (coins[i] < 0) continue;
            int cur_cost = distTo[i].first;
            if (cur_cost == INT_MAX) continue;
            for (int j = i - 1; j >= i - maxJump && j >= 0; --j) {
                if (coins[j] < 0) continue;
                int next_cost = cur_cost + coins[j];
                if (next_cost <= distTo[j].first) {
                    distTo[j].first = next_cost;
                    distTo[j].second = i;
                }
            }
        }
        
        if (distTo[0].second == -1) return {};
        
        vector<int> ans;
        int i = 0;
        while (0 <= i && i < n) {
            ans.push_back(i + 1);
            i = distTo[i].second;
        }
        return ans;
    }
};