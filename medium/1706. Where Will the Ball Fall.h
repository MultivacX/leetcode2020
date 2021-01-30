// 1706. Where Will the Ball Fall
// https://leetcode.com/problems/where-will-the-ball-fall/

// Runtime: 20 ms, faster than 99.41% of C++ online submissions for Where Will the Ball Fall.
// Memory Usage: 13 MB, less than 99.95% of C++ online submissions for Where Will the Ball Fall.
    
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        vector<int> ans(N, -1);
        for (int j = 0; j < N; ++j) {
            int bi = 0, bj = j;
            while (bi < M) {
                // if (j == 0) cout << bi << ", " << bj << endl;
                if (grid[bi][bj] == 1) {
                    if (bj == N - 1 || grid[bi][bj + 1] == -1) {
                        bj = -1;
                        break;
                    } else {
                        ++bi;
                        ++bj;
                    }
                } else {
                    if (bj == 0 || grid[bi][bj - 1] == 1) {
                        bj = -1;
                        break;
                    } else {
                        ++bi;
                        --bj;
                    }
                }
            }
            ans[j] = bj;
        }
        return ans;
    }
};