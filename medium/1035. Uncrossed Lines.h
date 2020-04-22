// 1035. Uncrossed Lines

// Runtime: 12 ms, faster than 67.71% of C++ online submissions for Uncrossed Lines.
// Memory Usage: 9.7 MB, less than 77.27% of C++ online submissions for Uncrossed Lines.

// Runtime: O(M*N).
// Memory: O(M*N).

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        const int M = A.size();
        const int N = B.size();
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i][j] = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0) + 1;
                else dp[i][j] = max(j > 0 ? dp[i][j - 1] : 0, i > 0 ? dp[i - 1][j] : 0);
            }   
        }
        return dp[M - 1][N - 1];
    }
};