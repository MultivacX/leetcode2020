// 810. Chalkboard XOR Game
// https://leetcode.com/problems/chalkboard-xor-game/

// Runtime: 12 ms, faster than 36.90% of C++ online submissions for Chalkboard XOR Game.
// Memory Usage: 13 MB, less than 70.24% of C++ online submissions for Chalkboard XOR Game.
    
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        // ni ^ ... ^ nk ^ ... ^ nj != 0
        // exists nk: ni ^ ... ^ nj != 0
        
        if (nums.size() % 2 == 0)
            return true;
        
        int ans = 0;
        for (int i : nums) ans ^= i;
        return ans == 0;
    }
};