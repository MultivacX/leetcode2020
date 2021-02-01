// 959. Regions Cut By Slashes

// Runtime: 44 ms, faster than 12.65% of C++ online submissions for Regions Cut By Slashes.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Regions Cut By Slashes.

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int N = grid.size();
        vector<vector<bool>> squares(3 * N, vector<bool>(3 * N, false));
        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < grid[i].length(); ++j) 
                fill_square(i, j, grid[i][j], squares);
            
        // for (int i = 0; i < 3 * N; ++i) {
        //     for (int j = 0; j < 3 * N; ++j) {
        //         cout << (squares[i][j] ? 1 : 0);
        //     }
        //     cout << endl;
        // }
        
        int regions = 0;
        for (int i = 0; i < 3 * N; ++i) {
            for (int j = 0; j < 3 * N; ++j) {
                if (squares[i][j]) continue;
                ++regions;
                fill_region(i, j, squares);
            }
        }
        return regions;
    }
    
    void fill_square(int i, int j, char c, vector<vector<bool>>& squares) {
        if (c == ' ') return;
        
        int si = i * 3;
        int sj = j * 3;
        if (c == '/') {
            squares[0 + si][2 + sj] = true;
            squares[1 + si][1 + sj] = true;
            squares[2 + si][0 + sj] = true;
        } else {
            squares[0 + si][0 + sj] = true;
            squares[1 + si][1 + sj] = true;
            squares[2 + si][2 + sj] = true;
        }
    }
    
    void fill_region(int i, int j, vector<vector<bool>>& squares) {
        const int N = squares.size();
        if (i < 0 || i >= N || j < 0 || j >= N || squares[i][j]) return;
        
        squares[i][j] = true;
        fill_region(i - 1, j, squares);
        fill_region(i + 1, j, squares);
        fill_region(i, j - 1, squares);
        fill_region(i, j + 1, squares);
    }
};