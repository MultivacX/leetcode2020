// 1908. Game of Nim
// https://leetcode.com/problems/game-of-nim/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Nim.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Game of Nim.
    
class Solution {
public:
    bool nimGame(vector<int>& piles) {
        // [k]    win
        // [1, 1] lose
        // [1, n] win
        // [m, n] lose
        return accumulate(begin(piles), end(piles), 0, bit_xor());
    }
};