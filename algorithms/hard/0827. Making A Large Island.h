// 827. Making A Large Island
// https://leetcode.com/problems/making-a-large-island/

// Runtime: 44 ms, faster than 60.84% of C++ online submissions for Making A Large Island.
// Memory Usage: 12.4 MB, less than 60.81% of C++ online submissions for Making A Large Island.

class Solution {
    vector<int> areas;
    int N;
    int max_area;
    
    void f(vector<vector<int>>& grid, int i, int j, int& area, bool& zero_nearby) {
        if (i < 0 || i >= N || j < 0 || j >= N) return;
        if (grid[i][j] != 1) {
            if (grid[i][j] == 0) zero_nearby = true;
            return;
        }
        
        ++area;
        grid[i][j] = areas.size() + 50;
        
        f(grid, i - 1, j, area, zero_nearby);
        f(grid, i + 1, j, area, zero_nearby);
        f(grid, i, j - 1, area, zero_nearby);
        f(grid, i, j + 1, area, zero_nearby);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        max_area = 1;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 1) continue;
                
                int area = 0;
                bool zero_nearby = false;
                f(grid, i, j, area, zero_nearby);
                if (area > 0) {
                    areas.push_back(area);
                    max_area = max(max_area, area + (zero_nearby ? 1 : 0));
                }
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 0) continue;
                
                vector<int> areas_nearby;
                unordered_set<int> idx;
                
                if (i > 0 && grid[i - 1][j] > 0) { 
                    areas_nearby.push_back(areas[grid[i - 1][j] - 50]); 
                    idx.insert(grid[i - 1][j]); 
                }
                
                if (i + 1 < N && grid[i + 1][j] > 0 && idx.count(grid[i + 1][j]) == 0) { 
                    areas_nearby.push_back(areas[grid[i + 1][j] - 50]); 
                    idx.insert(grid[i + 1][j]); 
                }
                
                if (j > 0 && grid[i][j - 1] > 0 && idx.count(grid[i][j - 1]) == 0) { 
                    areas_nearby.push_back(areas[grid[i][j - 1] - 50]); 
                    idx.insert(grid[i][j - 1]); 
                }
                
                if (j + 1 < N && grid[i][j + 1] > 0 && idx.count(grid[i][j + 1]) == 0) { 
                    areas_nearby.push_back(areas[grid[i][j + 1] - 50]); 
                    idx.insert(grid[i][j + 1]); 
                }
                
                max_area = max(max_area, accumulate(begin(areas_nearby), end(areas_nearby), 1));
            }
        }
        
        return max_area;
    }
};