// 883. Projection Area of 3D Shapes
// https://leetcode.com/problems/projection-area-of-3d-shapes/

// Runtime: 296 ms, faster than 5.76% of C++ online submissions for Projection Area of 3D Shapes.
// Memory Usage: 23.9 MB, less than 5.26% of C++ online submissions for Projection Area of 3D Shapes.

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        const int N = grid.size();
        unordered_map<int, unordered_set<int>> xy;
        unordered_map<int, unordered_set<int>> yz;
        unordered_map<int, unordered_set<int>> zx;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] > 0) xy[x].insert(y);
                
                for (int z = 0; z < grid[x][y]; ++z) {
                    yz[y].insert(z);
                    zx[z].insert(x);
                }
            }    
        }
        int ans = 0;
        for (auto it : xy) ans += it.second.size();
        for (auto it : yz) ans += it.second.size();
        for (auto it : zx) ans += it.second.size();
        return ans;
    }
};