// 955. Delete Columns to Make Sorted II
// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/

// Runtime: 16 ms, faster than 56.96% of C++ online submissions for Delete Columns to Make Sorted II.
// Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Delete Columns to Make Sorted II.

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int M = A.size();
        if (M <= 1) return 0;
        const int N = A[0].length();
        
        int ans = 0;
        // B[i] <= B[i + 1]
        vector<string> B(M);
        for (int j = 0; j < N; ++j) {
            bool del = false;
            for (int i = 0; i < M - 1; ++i) {
                if (A[i][j] > A[i + 1][j] && B[i] == B[i + 1]) {
                    del = true;
                    ++ans;
                    break;
                }
            }
            if (del) continue;
            
            for (int i = 0; i < M; ++i) B[i] += A[i][j];
        }
        return ans;
    }
};