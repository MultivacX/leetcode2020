// 1252. Cells with Odd Values in a Matrix
// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

// Runtime: 8 ms, faster than 56.15% of C++ online submissions for Cells with Odd Values in a Matrix.
// Memory Usage: 8.1 MB, less than 66.43% of C++ online submissions for Cells with Odd Values in a Matrix.
    
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (const auto& rc : indices) 
            ++rows[rc[0]], ++cols[rc[1]];
        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                if ((rows[i] + cols[j]) % 2)
                    ++ans;
        return ans;
    }
};