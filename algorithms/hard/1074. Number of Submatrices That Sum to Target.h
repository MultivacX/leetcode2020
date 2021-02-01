// 1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

// Runtime: 1904 ms, faster than 7.82% of C++ online submissions for Number of Submatrices That Sum to Target.
// Memory Usage: 9.3 MB, less than 7.06% of C++ online submissions for Number of Submatrices That Sum to Target.

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = matrix[i][j]
                    + (i > 0 ? matrix[i - 1][j] : 0)
                    + (j > 0 ? matrix[i][j - 1] : 0)
                    - (i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0);
                
                for (int r = 0; r <= i; ++r) {
                    for (int c = 0; c <= j; ++c) {
                        int sum = matrix[i][j];
                        if (r != i) sum -= matrix[r][j];
                        if (c != j) sum -= matrix[i][c];
                        if (r != i && c != j) sum += matrix[r][c];
                        ans += sum == target;
                    }
                }
            }
        }
        return ans;
    }
};