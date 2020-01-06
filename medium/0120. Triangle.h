// 120. Triangle

// Runtime: 16 ms, faster than 8.16% of C++ online submissions for Triangle.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty()) return 0;
        int rows = triangle.size();
        vector<int> v(triangle.back());
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                v[j] = min(v[j], v[j + 1]) + triangle[i][j];
            }
        }
        return v[0];
    }
};