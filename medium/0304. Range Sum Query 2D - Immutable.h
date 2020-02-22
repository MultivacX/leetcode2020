// 304. Range Sum Query 2D - Immutable

// Runtime: 28 ms, faster than 49.22% of C++ online submissions for Range Sum Query 2D - Immutable.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Range Sum Query 2D - Immutable.

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // printf("[%d][%d](%2d) - [%d][%d](%2d) - [%d][%d](%2d) + [%d][%d](%2d)\n"
        //        , row2 + 1, col2 + 1, sums[row2 + 1][col2 + 1]
        //        , row1 + 0, col2 + 1, sums[row1 + 0][col2 + 1]
        //        , row2 + 1, col1 + 0, sums[row2 + 1][col1 + 0]
        //        , row1 + 0, col1 + 0, sums[row1 + 0][col1 + 0]);
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
    
    vector<vector<int>> sums;
    
    void sum(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return;
        const int n = matrix[0].size();
        if (n == 0) return;
        
        sums.emplace_back(vector<int>(n + 1, 0));
        // for (int j = 0; j <= n; ++j) {
        //     printf("[%d] ", j);
        // }
        // cout << endl;
        for (int i = 1; i <= m; ++i) {
            sums.emplace_back(vector<int>(n + 1, 0));
            // printf("[%d] ", i);
            for (int j = 1; j <= n; ++j) {
                sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
                // printf("%2d, ", sums[i][j]);
            }
            // cout << endl;
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */