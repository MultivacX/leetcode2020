// 1833. Maximum Ice Cream Bars
// https://leetcode.com/problems/maximum-ice-cream-bars/

// Runtime: 240 ms, faster than 19.57% of C++ online submissions for Maximum Ice Cream Bars.
// Memory Usage: 90.2 MB, less than 5.58% of C++ online submissions for Maximum Ice Cream Bars.
    
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // optim: sort costs
        map<int, int> bars;
        for (int i : costs) ++bars[i];
        int ans = 0;
        for (const auto& [cost, count] : bars) {
            int k = min(coins / cost, count);
            if (k == 0) break;
            ans += k;
            coins -= cost * k;
        }
        return ans;
    }
};