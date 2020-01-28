// 85. Maximal Rectangle



class Solution {
public:
	// Wrong 
	// 56 / 66 test cases passed.
    /*int maximalRectangle(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if (m == 0) return 0;
        auto n = matrix[0].size();
        if (n == 0) return 0;
        
        int ans = 0;
        vector<vector<int>> L(m, vector<int>(n, 0));
        vector<vector<int>> U(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                
                L[i][j] = 1 + (i == 0 ? 0 : L[i - 1][j]);
                U[i][j] = 1 + (j == 0 ? 0 : U[i][j - 1]);
                
                int l = min(L[i][j], 1 + (i == 0 || j == 0 ? 0 : L[i - 1][j - 1]));
                int u = min(U[i][j], 1 + (i == 0 || j == 0 ? 0 : U[i - 1][j - 1]));
                int a = l * u;
                
                ans = max(ans, L[i][j]);
                ans = max(ans, U[i][j]);
                ans = max(ans, a);
            }
        }
        return ans;
    }*/
};