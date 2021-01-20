// 1030. Matrix Cells in Distance Order
// https://leetcode.com/problems/matrix-cells-in-distance-order/

// Runtime: 40 ms, faster than 97.87% of C++ online submissions for Matrix Cells in Distance Order.
// Memory Usage: 13.9 MB, less than 99.70% of C++ online submissions for Matrix Cells in Distance Order.
    
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> cells(R * C, vector<int>{0, 0});
        for (int i = 0, k = 0; i < R; ++i)
            for (int j = 0; j < C; ++j, ++k)
                cells[k][0] = i, cells[k][1] = j;
        sort(begin(cells), end(cells), [=](const vector<int>& l, const vector<int>& r){
            return abs(r0 - l[0]) + abs(c0 - l[1]) < abs(r0 - r[0]) + abs(c0 - r[1]);
        });
        return cells;
    }
};