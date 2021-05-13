// 711. Number of Distinct Islands II
// https://leetcode.com/problems/number-of-distinct-islands-ii/

// Runtime: 276 ms, faster than 10.71% of C++ online submissions for Number of Distinct Islands II.
// Memory Usage: 49.3 MB, less than 10.71% of C++ online submissions for Number of Distinct Islands II.
    
class Solution {
    string rr(const vector<pair<int, int>>& island) {
        // rotation & reflection
        // (x, y) : (x, -y) (-x, y) (-x, -y)
        // (y, x) : (y, -x) (-y, x) (-y, -x)
        vector<vector<pair<int, int>>> shapes(8);
        for (const auto& [x, y] : island) {
            shapes[0].push_back({x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, y});
            shapes[3].push_back({-x, -y});
            
            shapes[4].push_back({y, x});
            shapes[5].push_back({y, -x});
            shapes[6].push_back({-y, x});
            shapes[7].push_back({-y, -x});
        }
        
        for (auto& s : shapes) sort(begin(s), end(s));
        for (auto& s : shapes) {
            int minx = INT_MAX;
            int miny = INT_MAX;
            for (const auto& [x, y] : s) {
                minx = min(minx, x);
                miny = min(miny, y);
            }
            for (auto& [x, y] : s) {
                x -= minx;
                y -= miny;
            }
        }
        sort(begin(shapes), end(shapes));
        
        string ans;
        for (const auto& s : shapes) {
            for (const auto& [x, y] : s) {
                ans += to_string(x) + "," + to_string(y) + " ";
            }
            ans += "|";
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& island) {
        static const vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        const int m = grid.size();
        const int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        
        grid[i][j] = -1;
        island.push_back({i, j});
        for (int k = 0; k < 4; ++k) 
            dfs(grid, i + dir[k][0], j + dir[k][1], island);
    }
    
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        unordered_set<string> islands;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<pair<int, int>> island;
                dfs(grid, i, j, island);
                if (!island.empty())
                    islands.insert(rr(island));
            }
        }
        return islands.size();
    }
};