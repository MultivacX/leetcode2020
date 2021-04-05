// 1812. Determine Color of a Chessboard Square
// https://leetcode.com/problems/determine-color-of-a-chessboard-square/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine Color of a Chessboard Square.
// Memory Usage: 5.8 MB, less than 80.00% of C++ online submissions for Determine Color of a Chessboard Square.
    
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a' + 1;
        int y = coordinates[1] - '0';
        return (x + y) & 1;
    }
};