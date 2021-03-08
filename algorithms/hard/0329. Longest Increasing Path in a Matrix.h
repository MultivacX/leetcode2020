// 329. Longest Increasing Path in a Matrix

// Runtime: 136 ms, faster than 25.39% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage: 25.8 MB, less than 9.09% of C++ online submissions for Longest Increasing Path in a Matrix.

// Time Complexity: O(M * N).
// Space Complexity: O(M * N).

class Solution {
    static const int L = 0;
    static const int T = 1;
    static const int R = 2;
    static const int B = 3;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        if (M == 0) return 0;
        const int N = matrix[0].size();
        if (N == 0) return 0;
        
        int ans = 1;
        vector<vector<vector<int>>> memo(M, vector<vector<int>>(N, vector<int>(4, 0)));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int len = max(max(memo[i][j][L], memo[i][j][R]), max(memo[i][j][T], memo[i][j][B]));
                if (len == 0) move(matrix, memo, i, j);
                len = max(max(memo[i][j][L], memo[i][j][R]), max(memo[i][j][T], memo[i][j][B]));
                ans = max(ans, len);
            }
        }
        return ans;
    }
    
    void move(vector<vector<int>>& matrix, vector<vector<vector<int>>>& memo, int i, int j) {    
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
            int len = max(memo[i - 1][j][T], max(memo[i - 1][j][L], memo[i - 1][j][R]));
            if (len == 0) move(matrix, memo, i - 1, j);
            len = max(memo[i - 1][j][T], max(memo[i - 1][j][L], memo[i - 1][j][R]));
            memo[i][j][T] = 1 + len;
        } else {
            memo[i][j][T] = 1;
        }
        
        if (i + 1 < M && matrix[i][j] < matrix[i + 1][j]) {
            int len = max(memo[i + 1][j][B], max(memo[i + 1][j][L], memo[i + 1][j][R]));
            if (len == 0) move(matrix, memo, i + 1, j);
            len = max(memo[i + 1][j][B], max(memo[i + 1][j][L], memo[i + 1][j][R]));
            memo[i][j][B] = 1 + len;
        } else {
            memo[i][j][B] = 1;
        }
        
        if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
            int len = max(memo[i][j - 1][L], max(memo[i][j - 1][T], memo[i][j - 1][B]));
            if (len == 0) move(matrix, memo, i, j - 1);
            len = max(memo[i][j - 1][L], max(memo[i][j - 1][T], memo[i][j - 1][B]));
            memo[i][j][L] = 1 + len;
        } else {
            memo[i][j][L] = 1;
        }
        
        if (j + 1 < N && matrix[i][j] < matrix[i][j + 1]) {
            int len = max(memo[i][j + 1][R], max(memo[i][j + 1][T], memo[i][j + 1][B]));
            if (len == 0) move(matrix, memo, i, j + 1);
            len = max(memo[i][j + 1][R], max(memo[i][j + 1][T], memo[i][j + 1][B]));
            memo[i][j][R] = 1 + len;
        } else {
            memo[i][j][R] = 1;
        }
    }
};


class Solution {
    int m;
    int n;
    vector<vector<int>> pathes;
    
    int walk(const vector<vector<int>>& matrix, int i, int j) {
        if (pathes[i][j] != 0) return pathes[i][j];
        
        int ans = 0;
        if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j]) ans = max(ans, walk(matrix, i - 1, j));
        if (i + 1 < m && matrix[i][j] < matrix[i + 1][j]) ans = max(ans, walk(matrix, i + 1, j));
        if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1]) ans = max(ans, walk(matrix, i, j - 1));
        if (j + 1 < n && matrix[i][j] < matrix[i][j + 1]) ans = max(ans, walk(matrix, i, j + 1));
        return pathes[i][j] = ans + 1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        pathes = vector<vector<int>>(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = max(ans, walk(matrix, i, j));
        return ans;
    }
};