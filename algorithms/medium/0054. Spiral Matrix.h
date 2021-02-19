// 54. Spiral Matrix

// Runtime: 4 ms, faster than 60.38% of C++ online submissions for Spiral Matrix.
// Memory Usage: 8.6 MB, less than 81.82% of C++ online submissions for Spiral Matrix.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        if (n == 0) return {};
        
        vector<int> ans;
        int step = 0;
        int L = 0;
        int R = n - 1;
        int T = 0;
        int B = m - 1;
        while (step < m * n) {
            for (int col = L; col <= R && step < m * n; ++col) {
                ans.emplace_back(matrix[T][col]);
                ++step;
            }
            ++T;
            
            for (int row = T; row <= B && step < m * n; ++row) {
                ans.emplace_back(matrix[row][R]);
                ++step;
            }
            --R;
            
            for (int col = R; col >= L && step < m * n; --col) {
                ans.emplace_back(matrix[B][col]);
                ++step;
            }
            --B;
            
            for (int row = B; row >= T && step < m * n; --row) {
                ans.emplace_back(matrix[row][L]);
                ++step;
            }
            ++L;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int k = 0, R = m, C = n;
        vector<int> v;
        while (v.size() < m * n) {
            for (int i = k, j = k, c = 0; c < C && v.size() < m * n; ++j, ++c) 
                v.push_back(matrix[i][j]);
            
            for (int i = k + 1, j = k + C - 1, c = 0; c < R - 2 && v.size() < m * n; ++i, ++c) 
                v.push_back(matrix[i][j]);
            
            for (int i = k + R - 1, j = k + C - 1, c = 0; c < C && v.size() < m * n; --j, ++c) 
                v.push_back(matrix[i][j]);
            
            for (int i = k + R - 2, j = k, c = 0; c < R - 2 && v.size() < m * n; --i, ++c) 
                v.push_back(matrix[i][j]);
            
            ++k, R -= 2, C -= 2;
        }
        return v;
    }
};