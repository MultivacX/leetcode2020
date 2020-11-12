// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

// Runtime: 16 ms, faster than 69.62% of C++ online submissions for Flood Fill.
// Memory Usage: 14.4 MB, less than 31.05% of C++ online submissions for Flood Fill.

class Solution {
    // const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int M;
    int N;
    int srcColor;
    int dstColor;
    
    void fill(vector<vector<int>>& image, vector<vector<int>>& ans, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || image[i][j] != srcColor || ans[i][j] < 0) return;
        ans[i][j] = dstColor;
        fill(image, ans, i - 1, j);
        fill(image, ans, i + 1, j);
        fill(image, ans, i, j - 1);
        fill(image, ans, i, j + 1);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        M = image.size();
        N = image[0].size();
        srcColor = image[sr][sc];
        dstColor = -newColor - 1;
        vector<vector<int>> ans(image);
        fill(image, ans, sr, sc);
        for (auto& v : ans) for (auto& i : v) if (i < 0) i = -i - 1;
        return ans;
    }
};