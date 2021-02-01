// 498. Diagonal Traverse

// Runtime: 72 ms, faster than 77.26% of C++ online submissions for Diagonal Traverse.
// Memory Usage: 13.1 MB, less than 100.00% of C++ online submissions for Diagonal Traverse.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        if (M == 0) return {};
        const int N = matrix[0].size();
        if (N == 0) return {};
        
        const int size = M * N;
        vector<int> ans(size, 0);
        int k = 0;
        int r = 0;
        int c = 0;
        bool move_tr = true; // move to top & right
        while (k < size) {
            if (r >= 0 && r < M && c >= 0 && c < N) {
                ans[k++] = matrix[r][c];
                if (move_tr) {
                    --r;
                    ++c;
                } else {
                    ++r;
                    --c;
                }
            } else if (move_tr) {
                move_tr = false;
                ++r;
                if (c >= N) {
                    ++r; 
                    c = N - 1;
                }
            } else {
                move_tr = true;
                ++c;
                if (r >= M) {
                    ++c;
                    r = M - 1;
                }
            }
        }
        return ans;
    }
};