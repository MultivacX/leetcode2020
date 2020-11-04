// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/

// Runtime: 4 ms, faster than 21.32% of C++ online submissions for Pascal's Triangle II.
// Memory Usage: 6.9 MB, less than 77.91% of C++ online submissions for Pascal's Triangle II.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tris{1};
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> tmp;
            for (int j = 0; j <= i; ++j)
                tmp.push_back((j > 0 ? tris[j - 1] : 0) + (j < i ? tris[j] : 0));
            swap(tris, tmp);
        }
        return tris;
    }
};