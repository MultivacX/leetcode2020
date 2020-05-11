// 835. Image Overlap

// Runtime: 88 ms, faster than 57.01% of C++ online submissions for Image Overlap.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Image Overlap.

// Time Complexity: O(M * N * M * N).
// Space Complexity: O(1).

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(slide(A, B), slide(B, A));
    }
    
    int slide(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int M = A.size();
        const int N = A[0].size();
        int ans = 0;
        for (int down = 1; down <= M; ++down) {
            for (int right = 1; right <= N; ++right) {
                int cnt = 0;
                for (int i = 0; i < down; ++i) {
                    for (int j = 0; j < right; ++j) {
                        if (A[M - down + i][N - right + j] + B[i][j] == 2)
                            ++cnt;
                    }
                }
                ans = max(ans, cnt);
            }    
        }
        return ans;
    }
};