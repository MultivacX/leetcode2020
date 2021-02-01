// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

// Runtime: 60 ms, faster than 100.00% of C++ online submissions for Smallest Rectangle Enclosing Black Pixels.
// Memory Usage: 16.5 MB, less than 100.00% of C++ online submissions for Smallest Rectangle Enclosing Black Pixels.
    
class Solution {
    int t;
    int d;
    int l;
    int r;
    int M;
    int N;
    
    void dfs(vector<vector<char>>& image, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || image[i][j] == '0') return;
        // cout << i << ", " << j << endl;
        t = min(t, i);
        d = max(d, i);
        l = min(l, j);
        r = max(r, j);
        image[i][j] = '0';
        dfs(image, i - 1, j);
        dfs(image, i + 1, j);
        dfs(image, i, j - 1);
        dfs(image, i, j + 1);
    }
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        M = image.size();
        if (M == 0) return 0;
        N = image[0].size();
        if (N == 0) return 0;
        t = x; d = x;
        l = y; r = y;
        dfs(image, x, y);
        // cout << t << ", " << d << "  " << l << ", " << r << endl;
        return (r - l + 1) * (d - t + 1);
    }
};