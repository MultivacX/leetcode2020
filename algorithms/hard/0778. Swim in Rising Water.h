// 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/

// Runtime: 16 ms, faster than 70.33% of C++ online submissions for Swim in Rising Water.
// Memory Usage: 8.7 MB, less than 79.68% of C++ online submissions for Swim in Rising Water.
    
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto cmp_min = [](const array<int, 3>& l, const array<int, 3>& r) { 
            return l[2] > r[2]; 
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp_min)> q(cmp_min);
        q.push({0, 0, grid[0][0]});
        grid[0][0] = -1;
        
        static const int directions[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
        };
        const int n = grid.size();
        int ans = 0;
        while (true) {
            int i = q.top()[0];
            int j = q.top()[1];
            int v = q.top()[2];
            ans = max(ans, v);
            q.pop();
            
            if (i == n - 1 && j == n - 1)
                return ans;
            
            for (int d = 0; d < 4; ++d) {
                int ni = i + directions[d][0];
                int nj = j + directions[d][1];
                
                if (ni == n - 1 && nj == n - 1) 
                    return max(ans, grid[ni][nj]);
                
                if (ni < 0 || ni >= n || nj < 0 || nj >= n || grid[ni][nj] < 0)
                    continue;
                
                q.push({ni, nj, grid[ni][nj]});
                grid[ni][nj] = -1;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         printf("%3d ", grid[i][j]);
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};