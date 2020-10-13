// 1605. Find Valid Matrix Given Row and Column Sums
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

// Runtime: 124 ms, faster than 41.71% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.
// Memory Usage: 33.7 MB, less than 5.53% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int M = rowSum.size();
        const int N = colSum.size();
        vector<vector<int>> m(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                m[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= m[i][j];
                colSum[j] -= m[i][j];
            }
        }
        return m;
    }
};