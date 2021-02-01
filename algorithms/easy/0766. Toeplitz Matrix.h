// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/

// Runtime: 36 ms, faster than 8.03% of C++ online submissions for Toeplitz Matrix.
// Memory Usage: 18.3 MB, less than 9.58% of C++ online submissions for Toeplitz Matrix.
    
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        list<int> row;
        for (int j = 0; j < N; ++j) 
            row.push_back(matrix[0][j]);
        for (int i = 1; i < M; ++i) {
            row.pop_back();
            row.push_front(matrix[i][0]);
            auto it = row.begin();
            for (int j = 0; j < N; ++j, ++it)
                if (matrix[i][j] != *it) 
                    return false;
        }
        return true;
    }
};