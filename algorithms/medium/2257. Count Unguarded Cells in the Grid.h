// 2257. Count Unguarded Cells in the Grid
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

// Runtime: 1079 ms, faster than 44.35% of C++ online submissions for Count Unguarded Cells in the Grid.
// Memory Usage: 153.9 MB, less than 59.27% of C++ online submissions for Count Unguarded Cells in the Grid.

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> cells(m, vector<int>(n));

        for (auto &w : walls)
            cells[w[0]][w[1]] = 0b1111;

        for (auto &g : guards)
            cells[g[0]][g[1]] = 0b1;

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (cells[i][j] == 0) cout << '-';
        //         else if (cells[i][j] == 0b1111) cout << 'W';
        //         else cout << 'G';
        //     }
        //     cout << endl;
        // }

        for (auto &g : guards)
        {
            int i = g[0], j = g[1];

            // up
            for (int k = i - 1; k >= 0; --k)
                if ((cells[k][j] & 0b11) == 0)
                    cells[k][j] = 0b10;
                else
                    break;

            // down
            for (int k = i + 1; k < m; ++k)
                if ((cells[k][j] & 0b11) == 0)
                    cells[k][j] = 0b10;
                else
                    break;

            // left
            for (int k = j - 1; k >= 0; --k)
                if ((cells[i][k] & 0b101) == 0)
                    cells[i][k] = 0b100;
                else
                    break;

            // right
            for (int k = j + 1; k < n; ++k)
                if ((cells[i][k] & 0b101) == 0)
                    cells[i][k] = 0b100;
                else
                    break;
        }

        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (cells[i][j] == 0)
                    ++res;
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (cells[i][j] == 0) cout << '-';
        //         else if (cells[i][j] == 0b1111) cout << 'W';
        //         else cout << 'G';
        //     }
        //     cout << endl;
        // }
        return res;
    }
};