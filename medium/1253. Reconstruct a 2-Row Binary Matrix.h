// 1253. Reconstruct a 2-Row Binary Matrix

// Runtime: 324 ms, faster than 22.02% of C++ online submissions for Reconstruct a 2-Row Binary Matrix.
// Memory Usage: 23.7 MB, less than 100.00% of C++ online submissions for Reconstruct a 2-Row Binary Matrix.

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum = accumulate(colsum.begin(), colsum.end(), 0);
        if (upper + lower != sum) return {};
        
        const int m = 2;
        const int n = colsum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            if (colsum[j] != 2) continue;
            --upper;
            --lower;
            sum -= 2;
            ans[0][j] = 1;
            ans[1][j] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (colsum[j] != 1) continue;
            if (upper > 0) {
                --upper;
                ans[0][j] = 1;
            } else if (lower > 0) {
                --lower;
                ans[1][j] = 1;
            }
            --sum;
        }
        return (upper == 0 && lower == 0 && sum == 0) ? ans : vector<vector<int>>();
    }
};