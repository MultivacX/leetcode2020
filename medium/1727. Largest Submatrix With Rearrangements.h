// 1727. Largest Submatrix With Rearrangements
// https://leetcode.com/problems/largest-submatrix-with-rearrangements/

// Runtime: 176 ms, faster than 73.72% of C++ online submissions for Largest Submatrix With Rearrangements.
// Memory Usage: 59.3 MB, less than 87.68% of C++ online submissions for Largest Submatrix With Rearrangements.
    
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        for (int i = 1; i < M; ++i) 
            for (int j = 0; j < N; ++j) 
                if (matrix[i][j]) 
                    matrix[i][j] += matrix[i - 1][j];
        
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            sort(rbegin(matrix[i]), rend(matrix[i]));
            for (int j = 0; j < N && matrix[i][j] > 0; ++j) 
                ans = max(ans, matrix[i][j] * (j + 1));
        }
        return ans;
    }
};