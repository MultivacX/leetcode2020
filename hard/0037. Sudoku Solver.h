// 37. Sudoku Solver

// Runtime: 4 ms, faster than 97.79% of C++ online submissions for Sudoku Solver.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Sudoku Solver.

class Solution {
public:
    // sqr[p][q]
    // p = (r / 3) * 3 + c / 3
    // q = (r % 3) * 3 + c % 3
    // void print_sqr() {
    //     for (int r = 0; r < 9; ++r) {
    //         for (int c = 0; c < 9; ++c) {
    //             int p = (r / 3) * 3 + c / 3;
    //             int q = (r % 3) * 3 + c % 3;
    //             printf("(%d,%d) ", p, q);
    //         }
    //         cout << endl;
    //     }
    // }
    // void print_mem(const char* info, vector<int>& v) {
    //     for (int i = 0; i < 9; ++i) {
    //         printf("%s[%d]:%s\n", info, i, bitset<9>(v[i]).to_string().c_str());
    //     }
    // }
    
    vector<int> rows = vector<int>(9, 0);
    vector<int> cols = vector<int>(9, 0);
    vector<int> sqrs = vector<int>(9, 0);
    // 111111111
    // bool satisfied(int rcs) { return rcs == 511; }
    
    vector<int> empty_cells;
    
    void solveSudoku(vector<vector<char>>& board) {
        // print_sqr();
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    empty_cells.push_back(r * 9 + c);
                    continue;
                }
                
                int p = (r / 3) * 3 + c / 3;
                
                int i = 1 << (board[r][c] - '0' - 1);
                rows[r] |= i;
                cols[c] |= i;
                sqrs[p] |= i;
            }
        }
        // printf("        987654321\n");
        // print_mem("rows", rows);
        // print_mem("cols", cols);
        // print_mem("sqrs", sqrs);
        
        fill(board, 0);
    }
    
    bool fill(vector<vector<char>>& board, int idx) {
        if (idx >= empty_cells.size()) return true;
        
        int r = empty_cells[idx] / 9;
        int c = empty_cells[idx] % 9;
        int p = (r / 3) * 3 + c / 3;
        for (int v = 1; v <= 9; ++v) {
            int i = 1 << (v - 1);
            if (rows[r] & i) continue;
            if (cols[c] & i) continue;
            if (sqrs[p] & i) continue;
            
            rows[r] |= i;
            cols[c] |= i;
            sqrs[p] |= i;
            ++idx;
            board[r][c] = '0' + v;
            
            if (fill(board, idx)) return true;
            
            rows[r] &= ~i;
            cols[c] &= ~i;
            sqrs[p] &= ~i;
            --idx;
            board[r][c] = '.';
        }
        
        return false;
    }
};