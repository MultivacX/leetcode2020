// 1351. Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// Runtime: 24 ms, faster than 98.52% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 10.7 MB, less than 94.31% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
    
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        int ans = 0;
        for (int i = 0, j = N; i < M; ++i) {
            ans += N - j;
            while (j > 0 && grid[i][j - 1] < 0)
                ++ans, --j;
        }
        return ans;
    }
};