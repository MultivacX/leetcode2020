// 1901. Find a Peak Element II
// https://leetcode.com/problems/find-a-peak-element-ii/

// Runtime: 164 ms, faster than 100.00% of C++ online submissions for Find a Peak Element II.
// Memory Usage: 46.2 MB, less than 100.00% of C++ online submissions for Find a Peak Element II.
    
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        
        int i = 0, j = 0;
        while (true) {
            static const vector<vector<int>> ds{
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
            };
            bool found = false;
            for (const auto& d : ds) {
                int ni = i + d[0], nj = j + d[1];
                if (0 <= ni && ni < m && 0 <= nj && nj < n && mat[ni][nj] > mat[i][j]) {
                    i = ni, j = nj;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        return {i, j};
    }
};