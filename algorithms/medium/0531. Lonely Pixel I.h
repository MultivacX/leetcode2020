// 531. Lonely Pixel I
// https://leetcode.com/problems/lonely-pixel-i/

// Runtime: 116 ms, faster than 86.47% of C++ online submissions for Lonely Pixel I.
// Memory Usage: 17.1 MB, less than 43.61% of C++ online submissions for Lonely Pixel I.
    
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        const int m = picture.size();
        const int n = picture[0].size();
        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B')
                    ++r[i], ++c[j];
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B' && r[i] == 1 && c[j] == 1)
                    ++ans;
        return ans;
    }
};