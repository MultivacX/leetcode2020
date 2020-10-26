// 799. Champagne Tower
// https://leetcode.com/problems/champagne-tower/

// Runtime: 4 ms, faster than 94.59% of C++ online submissions for Champagne Tower.
// Memory Usage: 10.2 MB, less than 18.47% of C++ online submissions for Champagne Tower.

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row + query_glass == 0) return min(poured, 1);
        
        vector<double> dp;
        double poured_ = poured;
        for (int row = 0; row <= query_row && poured_ > 0; ++row) {
            if (row == 0) {
                dp.push_back(poured_);
                continue;
            }
            
            poured_ = 0;
            vector<double> tmp(row + 1, 0);
            for (int i = 0; i <= row; ++i) {
                double topl = (i == 0   ? 0 : (dp[i - 1] > 1 ? dp[i - 1] - 1 : 0)) * 0.5;
                double top  = (i >= row ? 0 : (dp[i] > 1     ? dp[i] - 1     : 0)) * 0.5;
                tmp[i] = topl + top;
                poured_ += tmp[i];
            }
            // for (int i = 0; i < row; ++i) cout << dp[i] << " "; cout << endl;
            if (row == query_row) return min(tmp[query_glass], 1.0);
            swap(dp, tmp);
        }
        return 0;
    }
};