// 293. Flip Game
// https://leetcode.com/problems/flip-game/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Flip Game.
// Memory Usage: 7.9 MB, less than 34.25% of C++ online submissions for Flip Game.
    
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 0; i + 1 < s.length(); ++i) {
            if (s[i] == '+' && s[i] == s[i + 1]) {
                string t(s);
                t[i] = t[i + 1] = '-';
                ans.push_back(t);
            }
        }
        return ans;
    }
};