// 803. Bricks Falling When Hit
// https://leetcode.com/problems/bricks-falling-when-hit/

class Solution {
    // {i, j, bit position}
    const vector<vector<int>> directions{
        {-1,  0, 1},
        { 1,  0, 2},
        { 0, -1, 3},
        { 0,  1, 4},
    };
    int M;
    int N;
    
    /*void init(vector<vector<int>>& grid, int iFrom, int jFrom, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) return;
        if (i == 0 && grid[i][j] != -1) return;
        if (i == 0) grid[i][j] = 1;
        
        for (const auto& d : directions) {
            if (iFrom + d[0] == i && jFrom + d[1] == j) {
                if (grid[i][j] & (1 << d[2])) return;
                grid[i][j] |= (1 << d[2]);
                break;
            }
        }
        
        for (const auto& d : directions) 
            init(grid, i, j, i + d[0], j + d[1]);
    }*/
    
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        M = grid.size();
        if (M == 1) return vector<int>(hits.size(), 0);
        N = grid[0].size();
        
        // group[x]={grid[0][x...]==1}, [x,x+1,x+2...]
        // k=i*N+j, connect[k]={j}, grid[0][j]==1
        
        // first row as root
        for (int k = 0; k < N; ++k) {
            if (grid[0][k] == 0 || grid[1][k] == 0) continue;
            
            for (int i = 1; i < M; ++i) {
                for (int j = k; j >= 0; --j) {
                    if (grid[i][j] == 0) break;
                    
                }
                for (int j = k + 1; j < N; ++j) {
                    if (grid[i][j] == 0) break;
                    // top
                    // left
                }
            }
        }
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << bitset<5>(grid[i][j]) << " ";
            }
            cout << endl;
        }
        
        return {};
    }
};