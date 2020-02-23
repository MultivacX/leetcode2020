// 407. Trapping Rain Water II

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