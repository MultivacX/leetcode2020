// 892. Surface Area of 3D Shapes
// https://leetcode.com/problems/surface-area-of-3d-shapes/

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Surface Area of 3D Shapes.
// Memory Usage: 9.7 MB, less than 24.15% of C++ online submissions for Surface Area of 3D Shapes.

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int N = grid.size();
        auto getArea = [&](int i, int j){
            int area = 2;
            int h = grid[i][j];
            
            int t = (i > 0 ? grid[i - 1][j] : 0);
            area += h > t ? h - t : 0;
            
            t = (i + 1 < N ? grid[i + 1][j] : 0);
            area += h > t ? h - t : 0;
            
            t = (j > 0 ? grid[i][j - 1] : 0);
            area += h > t ? h - t : 0;
            
            t = (j + 1 < N ? grid[i][j + 1] : 0);
            area += h > t ? h - t : 0;
            
            return area;
        };
        
        int area = 0;
        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < N; ++j)
                if (grid[i][j]) area += getArea(i, j);
        return area;
    }
};