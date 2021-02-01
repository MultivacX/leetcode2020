// 836. Rectangle Overlap
// https://leetcode.com/problems/rectangle-overlap/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rectangle Overlap.
// Memory Usage: 8.7 MB, less than 28.24% of C++ online submissions for Rectangle Overlap.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};