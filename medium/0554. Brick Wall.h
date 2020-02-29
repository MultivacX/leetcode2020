// 554. Brick Wall

// Runtime: 48 ms, faster than 86.08% of C++ online submissions for Brick Wall.
// Memory Usage: 18.4 MB, less than 100.00% of C++ online submissions for Brick Wall.

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> x_coordinates;
        for (const auto& bricks : wall) {
            const int n = bricks.size();
            int x = 0;
            for (int i = 0; i < n - 1; ++i) {
                x += bricks[i];
                ++x_coordinates[x];
                // cout << x << "  ";
            }
            // cout << endl;
        }
        const int rows = wall.size();
        int ans = rows;
        for (auto it : x_coordinates)
            ans = min(ans, rows - it.second);
        return ans;
    }
};