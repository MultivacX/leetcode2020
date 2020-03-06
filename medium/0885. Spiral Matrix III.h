// 885. Spiral Matrix III

// Runtime: 44 ms, faster than 100.00% of C++ online submissions for Spiral Matrix III.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Spiral Matrix III.

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        const int N = R * C;
        vector<vector<int>> matrix(N, vector<int>(2, 0));
        int n = 0;
        int step = 1;
        int r = r0; 
        int c = c0;
        matrix[n][0] = r;
        matrix[n][1] = c;
        ++n;
        while (n < N) {
            // move left
            for (int i = 0; i < step && n < N; ++i) {
                ++c;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    matrix[n][0] = r;
                    matrix[n][1] = c;
                    ++n;
                }
            }
            
            // move down
            for (int i = 0; i < step && n < N; ++i) {
                ++r;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    matrix[n][0] = r;
                    matrix[n][1] = c;
                    ++n;
                }
            }
            
            ++step;
            
            // move right
            for (int i = 0; i < step && n < N; ++i) {
                --c;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    matrix[n][0] = r;
                    matrix[n][1] = c;
                    ++n;
                }
            }
            
            // move up
            for (int i = 0; i < step && n < N; ++i) {
                --r;
                if (r >= 0 && r < R && c >= 0 && c < C) {
                    matrix[n][0] = r;
                    matrix[n][1] = c;
                    ++n;
                }
            }
            
            ++step;
        }
        return matrix;
    }
};