// 289. Game of Life

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Game of Life.

// Time Complexity: O(M * N).
// Space Complexity: O(1).

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	static const int under_population =  2; // 1 -> 0
    	static const int over_population  =  3; // 1 -> 0
    	static const int becomes_live     = -1; // 0 -> 1

    	int m = board.size();
    	if (m == 0) return;
    	int n = board.front().size();
    	if (n == 0) return;
    	for (int i = 0; i < m; ++i) {
    		for (int j = 0; j < n; ++j) {
    			int live_neighbors = 0;
    			if (i > 0     && j > 0     && board[i - 1][j - 1] > 0) ++live_neighbors;
    			if (i > 0                  && board[i - 1][j    ] > 0) ++live_neighbors;
    			if (i > 0     && j < n - 1 && board[i - 1][j + 1] > 0) ++live_neighbors;

    			if (             j > 0     && board[i    ][j - 1] > 0) ++live_neighbors;
    			if (             j < n - 1 && board[i    ][j + 1] > 0) ++live_neighbors;

    			if (i < m - 1 && j > 0     && board[i + 1][j - 1] > 0) ++live_neighbors;
    			if (i < m - 1              && board[i + 1][j    ] > 0) ++live_neighbors;
    			if (i < m - 1 && j < n - 1 && board[i + 1][j + 1] > 0) ++live_neighbors;

    			if (board[i][j] <= 0 && live_neighbors == 3) {
    				board[i][j] = becomes_live;
    			} else if (board[i][j] > 0) {
    				if (live_neighbors < 2) board[i][j] = under_population;
    				else if (live_neighbors > 3) board[i][j] = over_population;
    			}
    		}
    	}

    	for (int i = 0; i < m; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (board[i][j] == becomes_live) board[i][j] = 1;
    			else if (board[i][j] == under_population || board[i][j] == over_population) board[i][j] = 0;
    		}
    	}
    }
};