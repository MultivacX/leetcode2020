// 59. Spiral Matrix II

// Runtime: 8 ms, faster than 13.06% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Spiral Matrix II.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int step = 0;
        int L = 0;
        int R = n - 1;
        int T = 0;
        int B = n - 1;
        while (step < n * n) {
            for (int col = L; col <= R && step < n * n; ++col) {
                ++step;
                ans[T][col] = step;
            }
            ++T;
            
            for (int row = T; row <= B && step < n * n; ++row) {
                ++step;
                ans[row][R] = step;
            }
            --R;
            
            for (int col = R; col >= L && step < n * n; --col) {
                ++step;
                ans[B][col] = step;
            }
            --B;
            
            for (int row = B; row >= T && step < n * n; --row) {
                ++step;
                ans[row][L] = step;
            }
            ++L;
        }
        return ans;
    }
};