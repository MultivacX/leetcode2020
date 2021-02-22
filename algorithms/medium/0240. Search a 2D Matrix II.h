// 240. Search a 2D Matrix II

// Runtime: 292 ms, faster than 12.03% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.9 MB, less than 73.33% of C++ online submissions for Search a 2D Matrix II.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int end = -1;
        for (const auto& row : matrix) {
            if (end < 0) end = row.size();
            auto it = lower_bound(row.begin(), row.begin() + end, target);
            if (it == row.end()) continue;
            if (*it == target) return true;
            if (it == row.begin()) break;
            end = it - row.begin();
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            matrix[i][j] > target ? --j : ++i;
        }
        return false;
    }
};