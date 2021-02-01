// 1482. Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Runtime: 296 ms, faster than 68.48% of C++ online submissions for Minimum Number of Days to Make m Bouquets.
// Memory Usage: 63.8 MB, less than 8.98% of C++ online submissions for Minimum Number of Days to Make m Bouquets.

class Solution {
    bool check(vector<int>& bloomDay, int m, int k, int D) {
        int bouquets = 0;
        int flowers = 0;
        for (int d : bloomDay) {
            if (d <= D) {
                if (++flowers == k) {
                    if (++bouquets == m)
                        return true;
                    flowers = 0;
                }
            } else flowers = 0;
        }
        return bouquets >= m;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) return -1;
        int R = *max_element(begin(bloomDay), end(bloomDay));
        if (bloomDay.size() == m * k) return R;
        
        int L = 1;
        R += 1;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (check(bloomDay, m, k, M)) R = M;
            else L = M + 1;
        }
        return L;
    }
};