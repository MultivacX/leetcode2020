// 407. Trapping Rain Water II

// Runtime: 196 ms, faster than 5.22% of C++ online submissions for Trapping Rain Water II.
// Memory Usage: 19.3 MB, less than 12.50% of C++ online submissions for Trapping Rain Water II.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int m = heightMap.size();
        if (m <= 2) return 0;
        const int n = heightMap[0].size();
        if (n <= 2) return 0;
        
        static const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        auto cmp = [&](vector<int>& left, vector<int>& right) { 
            return heightMap[left[0]][left[1]] > heightMap[right[0]][right[1]]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {q.push({i, 0}); visited[i][0] = true; }
        for (int i = 0; i < m; ++i) {q.push({i, n - 1}); visited[i][n - 1] = true; }
        for (int j = 1; j < n - 1; ++j) {q.push({0, j}); visited[0][j] = true; }
        for (int j = 1; j < n - 1; ++j) {q.push({m - 1, j}); visited[m - 1][j] = true; }
        
        int ans = 0;
        int height = INT_MIN;
        while (!q.empty()) {
            int i = q.top()[0];
            int j = q.top()[1];
            q.pop();
            
            if (!visited[i][j]) {
                ans += height > heightMap[i][j] ? height - heightMap[i][j] : 0;
                visited[i][j] = true;
            }
            height = max(height, heightMap[i][j]);
            
            for (int d = 0; d < 4; ++d) {
                int ti = i + directions[d][0];
                int tj = j + directions[d][1];
                if (ti < 0 || ti >= m || tj < 0 || tj >= n || visited[ti][tj])
                        continue;
                q.push({ti, tj});
            }
        }
        return ans;
    }
};

// WRONG 
// 23 / 40 test cases passed.
/*class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int m = heightMap.size();
        if (m <= 2) return 0;
        const int n = heightMap[0].size();
        if (n <= 2) return 0;
        
        // auto print = [](vector<vector<int>>& v) {
        //     const int m = v.size();
        //     const int n = v[0].size();
        //     printf("    ");
        //     for (int j = 0; j < n; ++j) {
        //         printf("%2d ", j);
        //     }
        //     cout << endl;
        //     for (int i = 0; i < m; ++i) {
        //         printf("%2d: ", i);
        //         for (int j = 0; j < n; ++j) {
        //             printf("%2d,", v[i][j] == INT_MIN ? -1 : v[i][j]);
        //         }
        //         cout << endl;
        //     }    
        //     cout << endl;
        // };
        // print(heightMap);
        
        vector<vector<int>> v(heightMap);
        
        for (int i = 1; i < m - 1; ++i) {
            int val = heightMap[i][0];
            for (int j = 1; j < n - 1; ++j) {
                val = max(val, heightMap[i][j]);
                v[i][j] = val;
            }
            
            val = heightMap[i][n - 1];
            for (int j = n - 2; j >= 1; --j) {
                val = max(val, heightMap[i][j]);
                v[i][j] = min(v[i][j], val);
            }
        }
        // print(v);
        for (int j = 1; j < n - 1; ++j) {
            int val = heightMap[0][j];
            for (int i = 1; i < m - 1; ++i) {
                val = max(val, heightMap[i][j]);
                v[i][j] = min(v[i][j], val);
            }
            
            val = heightMap[m - 1][j];
            for (int i = m - 2; i >= 1; --i) {
                val = max(val, heightMap[i][j]);
                v[i][j] = min(v[i][j], val);
            }
        }
        // print(v);
        
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                vector<int> blocks;
                int h = INT_MAX;
                f(heightMap, v, i, j, blocks, h);
                for (int b : blocks) 
                    ans += h - b;
            }
        }
        // print(v);
        return ans;
    }
    
    void f(const vector<vector<int>>& heightMap, vector<vector<int>>& v, int i, int j, vector<int>& blocks, int& h) {
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        
        if (i < 1 || i > m - 2 || j < 1 || j > n - 2 || v[i][j] == INT_MAX || v[i][j] <= heightMap[i][j]) 
            return;
        
        blocks.push_back(heightMap[i][j]);
        h = min(h, v[i][j]);
        h = min(h, min(v[i - 1][j], v[i + 1][j]));
        h = min(h, min(v[i][j - 1], v[i][j + 1]));
        v[i][j] = INT_MAX;
        
        f(heightMap, v, i - 1, j, blocks, h);
        f(heightMap, v, i + 1, j, blocks, h);
        f(heightMap, v, i, j - 1, blocks, h);
        f(heightMap, v, i, j + 1, blocks, h);
    }
};*/