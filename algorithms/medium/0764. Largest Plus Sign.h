// 764. Largest Plus Sign

// Runtime: 232 ms, faster than 60.69% of C++ online submissions for Largest Plus Sign.
// Memory Usage: 42.1 MB, less than 50.00% of C++ online submissions for Largest Plus Sign.

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> LR(N, vector<int>(N, 1));
        vector<vector<int>> TB(N, vector<int>(N, 1));
        for (auto& m : mines) LR[m[0]][m[1]] = 0, TB[m[0]][m[1]] = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (LR[i][j] == 0) continue;
                LR[i][j] = 1 + (j > 0 ? LR[i][j - 1] : 0); // left
                TB[i][j] = 1 + (i > 0 ? TB[i - 1][j] : 0); // top
            }
        }
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         cout << LR[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (LR[i][j] == 0) continue;
                LR[i][j] = min(LR[i][j], 1 + (j + 1 < N ? LR[i][j + 1] : 0));
                TB[i][j] = min(TB[i][j], 1 + (i + 1 < N ? TB[i + 1][j] : 0));
            }
        }
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max(ans, min(LR[i][j], TB[i][j]));
            }
        }
        return ans;
    }
};