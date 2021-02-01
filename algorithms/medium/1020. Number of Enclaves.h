// 1020. Number of Enclaves

// Runtime: 60 ms, faster than 55.76% of C++ online submissions for Number of Enclaves.
// Memory Usage: 14.7 MB, less than 93.75% of C++ online submissions for Number of Enclaves.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        for (int j = 0; j < n; ++j) {
            setLand(A, 0, j);
            setLand(A, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            setLand(A, i, 0);
            setLand(A, i, n - 1);
        }
        
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans += setIsland(A, i, j);
            }
        }
        return ans;
    }
    
    void setLand(vector<vector<int>>& A, int i, int j) {
        int m = A.size();
        int n = A[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1) return;
        
        A[i][j] = -1;
        setLand(A, i - 1, j);
        setLand(A, i + 1, j);
        setLand(A, i, j - 1);
        setLand(A, i, j + 1);
    }
    
    int setIsland(vector<vector<int>>& A, int i, int j) {
        int m = A.size();
        int n = A[0].size();
        if (i < 1 || i > m || j < 1 || j > n || A[i][j] != 1) return 0;
        
        A[i][j] = -2;
        return 1 + 
            setIsland(A, i - 1, j) +
            setIsland(A, i + 1, j) +
            setIsland(A, i, j - 1) +
            setIsland(A, i, j + 1);
    }
};