// 1594. Maximum Non Negative Product in a Matrix
// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

// Runtime: 12 ms, faster than 60.46% of C++ online submissions for Maximum Non Negative Product in a Matrix.
// Memory Usage: 10.6 MB, less than 5.12% of C++ online submissions for Maximum Non Negative Product in a Matrix.

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {        
        const int M = grid.size();
        const int N = grid[0].size();
        
        vector<vector<array<int64_t, 2>>> products(M, vector<array<int64_t, 2>>(N, array<int64_t, 2>{0, 0}));
        
        products[0][0][0] = products[0][0][1] = grid[0][0];
        for (int i = 1; i < M; ++i)
            products[i][0][0] = products[i][0][1] = products[i - 1][0][0] * grid[i][0];
        for (int j = 1; j < N; ++j)
            products[0][j][0] = products[0][j][1] = products[0][j - 1][0] * grid[0][j];
        
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                int64_t min_ = min(products[i][j - 1][0], products[i - 1][j][0]);
                int64_t max_ = max(products[i][j - 1][1], products[i - 1][j][1]);
                if (grid[i][j] < 0) swap(min_, max_);
                products[i][j][0] = min_ * grid[i][j];
                products[i][j][1] = max_ * grid[i][j];
            }
        }
        return products[M - 1][N - 1][1] < 0 ? -1 : products[M - 1][N - 1][1] % 1000000007;
    }
};