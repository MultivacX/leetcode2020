// 294. Flip Game II
// https://leetcode.com/problems/flip-game-ii/

// Runtime: 320 ms, faster than 25.81% of C++ online submissions for Flip Game II.
// Memory Usage: 72.7 MB, less than 22.04% of C++ online submissions for Flip Game II.
    
class Solution {
public:
    bool canWin(string s) {
        const int N = s.length();
        for (int i = 0; i + 1 < N; ++i) 
            if (s[i] == '+' && s[i + 1] == '+' && !canWin(s.substr(0, i) + "--" + s.substr(i + 2)))
                return true;
        return false;
    }
};