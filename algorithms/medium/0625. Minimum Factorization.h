// 625. Minimum Factorization
// https://leetcode.com/problems/minimum-factorization/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Factorization.
// Memory Usage: 6.2 MB, less than 69.05% of C++ online submissions for Minimum Factorization.
    
class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 10) return a;
        
        vector<int> cnt(10, 0);
        int x[] = {9, 8, 7, 6, 5, 4, 3, 2};
        for (int i = 0; i < 8; ++i) {
            while (a % x[i] == 0) {
                ++cnt[x[i]];
                a /= x[i];
            }
        }
        if (a > 1) return 0;
        
        uint64_t ans = 0;
        for (int i = 0; i < 10; ++i) {
            while (cnt[i]-- > 0) {
                ans = ans * 10 + i;
                if (ans > (uint64_t)INT_MAX)
                    return 0;
            }
        }
        return ans;
    }
};