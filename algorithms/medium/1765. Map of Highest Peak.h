// 1765. Map of Highest Peak
// https://leetcode.com/problems/map-of-highest-peak/

// Runtime: 604 ms, faster than 9.09% of C++ online submissions for Map of Highest Peak.
// Memory Usage: 188.7 MB, less than 9.09% of C++ online submissions for Map of Highest Peak.
    
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size();
        const int n = isWater[0].size();
        
        vector<vector<int>> heights(m, vector<int>(n, -1));
        unordered_set<int> cells;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 0) continue;
                heights[i][j] = 0;
                cells.insert(i * n + j);
            }    
        }
        
        int h = 1;
        while (!cells.empty()) {
            unordered_set<int> tmp;
            for (int k : cells) {
                int ci = k / n, cj = k % n;
                static const vector<vector<int>> d{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (const auto& v : d) {
                    int i = ci + v[0], j = cj + v[1];
                    if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] != -1)
                        continue;
                    heights[i][j] = h;
                    tmp.insert(i * n + j);
                }
            }
            ++h;
            swap(cells, tmp);
        }
        return heights;
    }
};