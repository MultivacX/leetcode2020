// 1725. Number Of Rectangles That Can Form The Largest Square
// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

// Runtime: 36 ms, faster than 97.79% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
// Memory Usage: 18.3 MB, less than 78.95% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
    
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len = 0, cnt = 0;
        for (const auto& r : rectangles) {
            int l = min(r[0], r[1]);
            if (len < l) len = l, cnt = 0;
            if (len == l) ++cnt;
        }
        return cnt;
    }
};