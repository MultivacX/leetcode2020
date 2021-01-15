// 1572. Matrix Diagonal Sum
// https://leetcode.com/problems/matrix-diagonal-sum/

// Runtime: 12 ms, faster than 99.81% of C++ online submissions for Matrix Diagonal Sum.
// Memory Usage: 11.2 MB, less than 99.44% of C++ online submissions for Matrix Diagonal Sum.
    
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int N = mat.size();
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += mat[i][i];
            if (i != N - i - 1)
                sum += mat[i][N - i - 1];
        }
        return sum;
    }
};