// 1504. Count Submatrices With All Ones
// https://leetcode.com/problems/count-submatrices-with-all-ones/

// Wrong Answer
// 24 / 72 test cases passed.
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int M = mat.size();
        const int N = mat[0].size();
        
        int ans = 0;
        // {left, top}
        vector<vector<int>> pre(N, vector<int>{0, 0});
        for (int i = 0; i < M; ++i) {
            vector<vector<int>> cur(N, vector<int>{0, 0});
            for (int j = 0; j < N; ++j) {
                if (mat[i][j] == 0) {
                    // printf("[%d_%d][%d_%d]  ", 0, 0, 0, 0);
                    continue;
                }
                
                int l = 1 + (j == 0 ? 0 : cur[j - 1][0]);
                int t = 1 + pre[j][1];
                
                int l_ = min(l, 1 + (j == 0 ? 0 : pre[j - 1][0]));
                int t_ = min(t, 1 + (j == 0 ? 0 : pre[j - 1][1]));
                
                ans += l_ * t_;
                ans += (l - l_) + (t - t_);
                
                cur[j][0] = l;
                cur[j][1] = t;
                
                // printf("[%d_%d][%d_%d]  ", l, t, l_, t_);
            }
            // cout << endl;
            swap(cur, pre);
        }
        return ans;
    }
};