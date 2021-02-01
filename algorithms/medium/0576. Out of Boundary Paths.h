// 576. Out of Boundary Paths

// Runtime: 24 ms, faster than 31.76% of C++ online submissions for Out of Boundary Paths.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Out of Boundary Paths.

class Solution {
public:
    vector<vector<vector<int>>> v;
    
    int findPaths(int m, int n, int N, int i, int j) {
        if (N < 0) return 0;
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        
        if (v.empty()) v = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        else if (v[N][i][j] != -1) return v[N][i][j];
        
        v[N][i][j] = 0;
        v[N][i][j] = (v[N][i][j] + findPaths(m, n, N - 1, i - 1, j)) % 1000000007;
        v[N][i][j] = (v[N][i][j] + findPaths(m, n, N - 1, i + 1, j)) % 1000000007;
        v[N][i][j] = (v[N][i][j] + findPaths(m, n, N - 1, i, j - 1)) % 1000000007;
        v[N][i][j] = (v[N][i][j] + findPaths(m, n, N - 1, i, j + 1)) % 1000000007;
        
        return v[N][i][j];
    }
};