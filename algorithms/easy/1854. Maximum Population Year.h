// 1854. Maximum Population Year
// https://leetcode.com/problems/maximum-population-year/

// Runtime: 4 ms, faster than 71.43% of C++ online submissions for Maximum Population Year.
// Memory Usage: 7.8 MB, less than 42.86% of C++ online submissions for Maximum Population Year.
    
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int N = 2050 - 1950 + 1;
        vector<int> m(N, 0);
        for (const auto& l : logs) {
            ++m[l[0] - 1950];
            --m[l[1] - 1950];
        }
        int y = -1;
        for (int i = 0, p = 0, k = 0; i < N; ++i) {
            k += m[i];
            if (p < k) {
                y = i + 1950;
                p = k;
            }
        }
        return y;
    }
};