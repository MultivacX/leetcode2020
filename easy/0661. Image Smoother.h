// 661. Image Smoother
// https://leetcode.com/problems/image-smoother/

// Runtime: 84 ms, faster than 91.60% of C++ online submissions for Image Smoother.
// Memory Usage: 22 MB, less than 10.84% of C++ online submissions for Image Smoother.

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int D[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1},
                             {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        const int R = M.size();
        const int C = M[0].size();
        vector<vector<int>> N(R, vector<int>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int cnt = 1;
                double g = M[i][j];
                for (int k = 0; k < 8; ++k) {
                    int ii = i + D[k][0];
                    int jj = j + D[k][1];
                    if (ii < 0 || ii >= R || jj < 0 || jj >= C)
                        continue;
                    cnt += 1;
                    g += M[ii][jj];
                }
                N[i][j] = g / cnt;
            }
        }
        return N;
    }
};