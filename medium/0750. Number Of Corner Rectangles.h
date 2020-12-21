// 750. Number Of Corner Rectangles
// https://leetcode.com/problems/number-of-corner-rectangles/

// Runtime: 636 ms, faster than 30.67% of C++ online submissions for Number Of Corner Rectangles.
// Memory Usage: 27.7 MB, less than 42.33% of C++ online submissions for Number Of Corner Rectangles.
    
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M <= 1) return 0;
        const int N = grid[0].size();
        if (N <= 1) return 0;
        
        int ans = 0;
        // {j, {i, ...}}
        unordered_map<int, vector<int>> tops;
        for (int i = 0; i < M; ++i) {
            vector<int> left;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                // grid[i][j] : right bottom
                
                // int r = j;
                // int b = i;
                for (int t : tops[j])
                    for (int l : left)
                        if (grid[t][l] == 1)
                            ++ans;
                
                tops[j].push_back(i);
                left.push_back(j);
            } 
        }
        return ans;
    }
};