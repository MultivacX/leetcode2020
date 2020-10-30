// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

// Runtime: 152 ms, faster than 98.74% of C++ online submissions for Maximum Side Length of a Square with Sum Less than or Equal to Threshold.
// Memory Usage: 26.2 MB, less than 7.36% of C++ online submissions for Maximum Side Length of a Square with Sum Less than or Equal to Threshold.

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int M = mat.size();
        const int N = mat[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                // if (i > 0) mat[i][j] += mat[i - 1][j];
                if (j > 0) mat[i][j] += mat[i][j - 1];
                // cout << mat[i][j] << " ";
            }
            // cout << endl;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i > 0) mat[i][j] += mat[i - 1][j];
                // cout << mat[i][j] << " ";
            }
            // cout << endl;
        }
        
        int len = 0;
        for (int i = 0, k = 0; i + k < M; ++i) {
            for (int j = 0; j + k < N; ++j) {
                while (i + k < M && j + k < N) {
                    int sum = mat[i + k][j + k];
                    if (i > 0) sum -= mat[i - 1][j + k];
                    if (j > 0) sum -= mat[i + k][j - 1];
                    if (i > 0 && j > 0) sum += mat[i - 1][j - 1];
                    if (sum > threshold) break;
                    ++k;
                    len = k;
                }
            }
        }
        return len;
    }
};