// 861. Score After Flipping Matrix

// Runtime: 4 ms, faster than 61.68% of C++ online submissions for Score After Flipping Matrix.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Score After Flipping Matrix.

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        const int ROWS = A.size();
        const int COLS = A[0].size();
        
        vector<int> row_flips(ROWS, 0);
        vector<int> col_flips(COLS, 0);
        
        int scores = 0;
        
        for (int row = 0; row < ROWS; ++row)
            if (A[row][0] == 0) 
                ++row_flips[row];
        scores += ROWS * (1 << (COLS - 1));
        
        for (int col = 1; col < COLS; ++col) {
            int zero = 0;
            for (int row = 0; row < ROWS; ++row) 
                if ((A[row][col] + row_flips[row] + col_flips[col]) % 2)
                    ++zero;
            
            if (ROWS - zero >= zero) {
                scores += (ROWS - zero) * (1 << (COLS - 1 - col));
            } else {
                ++col_flips[col];
                scores += zero * (1 << (COLS - 1 - col));
            }
        }
        
        return scores;
    }
};