// 292. Nim Game
// https://leetcode.com/problems/nim-game/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nim Game.
// Memory Usage: 6.3 MB, less than 13.44% of C++ online submissions for Nim Game.
    
class Solution {
public:
    bool canWinNim(int n) {
        // [] take all  f(i, []) [321]
        // [] lose      f(4, []) [4]{321} [43]{21} [432]{1}
        
        // [5]   4321 = f(4, {})
        // [65]  4321 = f(4, {})
        // [765] 4321 = f(4, {})
        
        // [8]{765} 4321 = f(4, [])
        // [87]{65} 4321 = f(4, [])
        // [876]{5} 4321 = f(4, [])
        
        return n % 4;
    }
};