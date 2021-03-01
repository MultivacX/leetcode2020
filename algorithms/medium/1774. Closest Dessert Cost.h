// 1774. Closest Dessert Cost
// https://leetcode.com/problems/closest-dessert-cost/

// Runtime: 8 ms, faster than 83.33% of C++ online submissions for Closest Dessert Cost.
// Memory Usage: 10.5 MB, less than 50.00% of C++ online submissions for Closest Dessert Cost.
    
class Solution {
    set<int> sums;
    int ans = INT_MAX;
    
    void helper(const vector<int>& toppingCosts, int idx, int sum, int t) {
        sums.insert(sum);
        for (int i = idx; i < toppingCosts.size() && sum < t; ++i) 
            for (int j = 0; j < 3; ++j) 
                helper(toppingCosts, i + 1, sum + toppingCosts[i] * j, t);
    }
    
    void check(int cost, int target) {
        // cout << ans << ", " << cost << endl;
        if (abs(ans - target) > abs(cost - target))
            ans = cost;
        else if (abs(ans - target) == abs(cost - target) && ans > cost)
            ans = cost;
    }
    
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        sort(begin(baseCosts), end(baseCosts));
        sort(begin(toppingCosts), end(toppingCosts));
        
        for (int base : baseCosts) {
            if (base == target) return base;
            
            if (base > target) {
                if (abs(ans - target) > base - target) 
                    return base;
                break;
            }
            
            if (sums.empty()) 
                helper(toppingCosts, 0, 0, target - base);
            
            check(base, target);
            
            auto it = sums.lower_bound(target - base);
            if (it == sums.begin()) {
                check(base + *it, target);
            } else if (it == sums.end()) {
                --it;
                check(base + *it, target);
            } else {
                check(base + *it, target);
                --it;
                check(base + *it, target);
            }
        }
        return ans;
    }
};