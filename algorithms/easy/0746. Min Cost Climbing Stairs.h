// 746. Min Cost Climbing Stairs

// Runtime: 8 ms, faster than 61.58% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 8.8 MB, less than 81.40% of C++ online submissions for Min Cost Climbing Stairs.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n <= 2) return min(cost.front(), cost.back());
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < n; ++i) {
            int from_a = a + cost[i];
            int from_b = b + cost[i];
            a = b;
            b = min(from_a, from_b);
        }
        return min(a, b);
    }
};