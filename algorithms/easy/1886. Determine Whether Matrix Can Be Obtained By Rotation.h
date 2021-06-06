// 1886. Determine Whether Matrix Can Be Obtained By Rotation
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

// Runtime: 12 ms, faster than 20.00% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
// Memory Usage: 11 MB, less than 60.00% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
    
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n = mat.size();
        bool ans = true;
        
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j])
                    ans = false;
                a += mat[i][j];
                b += target[i][j];
            }
        }
        if (a != b) return false;
        if (ans) return ans;
        
        ans = true;
        for (int i = 0; i < n && ans; ++i) 
            for (int j = 0; j < n && ans; ++j) 
                if (mat[i][j] != target[j][n - 1 - i])
                    ans = false;
        if (ans) return ans;
        
        ans = true;
        for (int i = 0; i < n && ans; ++i) 
            for (int j = 0; j < n && ans; ++j) 
                if (mat[i][j] != target[n - 1 - j][i])
                    ans = false;
        if (ans) return ans;
        
        ans = true;
        for (int i = 0; i < n && ans; ++i) 
            for (int j = 0; j < n && ans; ++j) 
                if (mat[i][j] != target[n - 1 - i][n - 1 - j])
                    ans = false;
        return ans;
    }
};