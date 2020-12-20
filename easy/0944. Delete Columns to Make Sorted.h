// 944. Delete Columns to Make Sorted
// https://leetcode.com/problems/delete-columns-to-make-sorted/submissions/

// Runtime: 68 ms, faster than 12.37% of C++ online submissions for Delete Columns to Make Sorted.
// Memory Usage: 12.6 MB, less than 15.59% of C++ online submissions for Delete Columns to Make Sorted.
    
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int M = A.size();
        const int N = A[0].size();
        int d = 0;
        for (int j = 0; j < N; ++j) {
            for (int i = 1; i < M; ++i) {
                if (A[i - 1][j] <= A[i][j])
                    continue;
                ++d;
                break;
            }
        } 
        return d;
    }
};