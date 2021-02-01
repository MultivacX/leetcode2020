// 85. Maximal Rectangle

// Runtime: 24 ms, faster than 75.43% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 11.7 MB, less than 27.78% of C++ online submissions for Maximal Rectangle.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if (m == 0) return 0;
        auto n = matrix[0].size();
        if (n == 0) return 0;
        
        vector<int> heights(n, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            // cout << "h: ";
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j] += 1;
                // cout << heights[j] << ", ";
            }
            // cout << endl;
            ans = max(ans, area(heights, n));
        }
        return ans;
    }
    
    int area(const vector<int>& heights, const int n) {
        vector<int> l(n, -1);
        vector<int> r(n, -1);
        
        l[0] = 0;
        for (int j = 1; j < n; ++j) {
            l[j] = j;
            int k = j - 1;
            while (k >= 0 && heights[k] >= heights[j]) {
                l[j] = l[k];
                k = l[k] - 1;
            }
        }
        
        r[n - 1] = n - 1;
        for (int j = n - 2; j >= 0; --j) {
            r[j] = j;
            int k = j + 1;
            while (k < n && heights[k] >= heights[j]) {
                r[j] = r[k];
                k = r[k] + 1;
            }
        }
        
        // cout << "l: ";
        // for (int j = 0; j < n; ++j) cout << l[j] << ", ";
        // cout << endl;
        // cout << "r: ";
        // for (int j = 0; j < n; ++j) cout << r[j] << ", ";
        // cout << endl;
        
        // cout << "A: ";
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, (r[j] - l[j] + 1) * heights[j]);
            // cout << ans << ", ";
        }
        // cout << endl;
        
        return ans;
    }
};

// 56 / 66 test cases passed.
/*class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
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
    }
};*/