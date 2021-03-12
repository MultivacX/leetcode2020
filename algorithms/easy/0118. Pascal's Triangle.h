// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.8 MB, less than 79.64% of C++ online submissions for Pascal's Triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tris;
        for (int i = 0; i < numRows; ++i) {
            tris.push_back({});
            if (i == 0) {
                tris[i].push_back(1);
                continue;
            }
            for (int j = 0; j <= i; ++j) {
                tris[i].push_back((j > 0 ? tris[i - 1][j - 1] : 0) + (j < i ? tris[i - 1][j] : 0));
            }
        }
        return tris;
    }
};


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int size = 2; size <= numRows; ++size) {
            vector<int> row(size, 1);
            for (int i = 1; i + 1 < size; ++i)
                row[i] = ans.back()[i - 1] + ans.back()[i];
            ans.push_back(row);
        }
        return ans;
    }
};