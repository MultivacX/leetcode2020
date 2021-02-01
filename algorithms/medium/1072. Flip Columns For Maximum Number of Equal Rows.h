// 1072. Flip Columns For Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

// Runtime: 368 ms, faster than 98.53% of C++ online submissions for Flip Columns For Maximum Number of Equal Rows.
// Memory Usage: 69 MB, less than 81.37% of C++ online submissions for Flip Columns For Maximum Number of Equal Rows.

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        int ans = 0;
        unordered_map<string, int> m;
        for (auto& row : matrix) {
            string all0(N, '0');
            string all1(N, '0');
            // flip
            for (int j = 0; j < N; ++j) {
                if (row[j] == 0) all1[j] = '1';
                else all0[j] = '1';
            }
            ans = max(ans, ++m[all0]);
            ans = max(ans, ++m[all1]);
        }
        return ans;
    }
};