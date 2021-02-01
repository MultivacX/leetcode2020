// 867. Transpose Matrix

// Runtime: 28 ms, faster than 51.95% of C++ online submissions for Transpose Matrix.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Transpose Matrix.

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        const int m = A.size();
        const int n = A[0].size();
        vector<vector<int>> B(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                B[j][i] = A[i][j];
        return B;
    }
};