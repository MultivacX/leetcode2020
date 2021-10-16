// 2027. Minimum Moves to Convert String
// https://leetcode.com/problems/minimum-moves-to-convert-string/submissions/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Moves to Convert String.
// Memory Usage: 6.4 MB, less than 84.43% of C++ online submissions for Minimum Moves to Convert String.
    
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, k = 0;
        while (i < s.length()) 
            if (s[i] == 'X') i += 3, k += 1;
            else i += 1;
        return k;
    }
};