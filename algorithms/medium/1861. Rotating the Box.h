// 1861. Rotating the Box
// https://leetcode.com/problems/rotating-the-box/

// Runtime: 228 ms, faster than 71.43% of C++ online submissions for Rotating the Box.
// Memory Usage: 52.5 MB, less than 28.57% of C++ online submissions for Rotating the Box.
    
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int m = box.size();
        const int n = box[0].size();
        
        vector<vector<char>> ans(n, vector<char>(m));
        
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                ans[i][j] = box[m - 1 - j][i];
        
        for (int j = 0; j < m; ++j) {
            int i = n - 1;
            while (i >= 0) {
                while (i >= 0 && ans[i][j] != '.') --i;
                
                int t = i - 1;
                while (t >= 0) {
                    if (ans[t][j] == '*') {
                        i = t - 1;
                        break;
                    }
                    if (ans[t][j] == '#') {
                        swap(ans[i][j], ans[t][j]);
                        --i;
                    }
                    --t;
                }
                if (t < 0) break;
            }
        }
        
        return ans;
    }
};