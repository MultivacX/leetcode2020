// 218. The Skyline Problem

// Runtime: 36 ms, faster than 64.61% of C++ online submissions for The Skyline Problem.
// Memory Usage: 14.9 MB, less than 46.15% of C++ online submissions for The Skyline Problem.

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        
        vector<vector<int64_t>> edges(buildings.size() * 2, vector<int64_t>(2, 0));
        for (int i = 0; i < buildings.size(); ++i) {
            // the left edge of the ith building
            edges[2 * i][0] = buildings[i][0];
            edges[2 * i][1] = -1 * (int64_t)buildings[i][2];
            
            // the right edge of the ith building
            edges[2 * i + 1][0] = buildings[i][1];
            edges[2 * i + 1][1] = (int64_t)buildings[i][2];
        }
        sort(edges.begin(), edges.end(), [](vector<int64_t>& left, vector<int64_t>& right){
            return left[0] < right[0] || (left[0] == right[0] && left[1] < right[1]);
        });
        
        multiset<int> heights;
        int pre_max_h = 0;
        vector<vector<int>> coordinates;
        for (const auto& edge : edges) {
            int x = edge[0];
            bool left = edge[1] < 0;
            int cur_h = left ? -edge[1] : edge[1];
            if (left) {
                pre_max_h = heights.empty() ? 0 : *heights.rbegin();
                heights.emplace(cur_h);
            } else {
                heights.erase(heights.find(cur_h));
                pre_max_h = heights.empty() ? 0 : *heights.rbegin();
            }
            
            if (heights.empty()) {
                coordinates.push_back({x, 0});
            } else if (left) {
                if (cur_h > pre_max_h) {
                    coordinates.push_back({x, cur_h});
                }
            } else if (cur_h > pre_max_h) {
                coordinates.push_back({x, pre_max_h});
            }
        }
        return coordinates;
    }
};