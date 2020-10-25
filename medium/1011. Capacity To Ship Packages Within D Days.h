// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Runtime: 104 ms, faster than 51.51% of C++ online submissions for Capacity To Ship Packages Within D Days.
// Memory Usage: 26.6 MB, less than 10.61% of C++ online submissions for Capacity To Ship Packages Within D Days.

class Solution {
    bool check(vector<int>& weights, int D, int targetWeights) {
        const int N = weights.size();
        int curWeights = weights[0];
        int days = 1;
        for (int i = 1; i < N; ++i) {
            curWeights += weights[i];
            if (curWeights > targetWeights) {
                // can not load the i-th package in current day
                // try to load the i-th package in next day
                if (++days > D) return false;
                curWeights = weights[i];
            }
        }
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int D) {
        const int N = weights.size();
        int maxWeight = *max_element(begin(weights), end(weights));
        int sum = accumulate(begin(weights), end(weights), 0);
        if (N == D) return maxWeight;
        if (1 == D) return sum;
        
        // search space : [LW, RW)
        int LW = maxWeight;
        int RW = sum + 1;
        while (LW < RW) {
            int MW = LW + (RW - LW) / 2;
            if (check(weights, D, MW)) RW = MW;
            else LW = MW + 1;
        }
        return LW;
    }
};