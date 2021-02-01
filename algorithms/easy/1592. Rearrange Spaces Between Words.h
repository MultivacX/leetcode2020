// 1592. Rearrange Spaces Between Words
// https://leetcode.com/problems/rearrange-spaces-between-words/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rearrange Spaces Between Words.
// Memory Usage: 6.6 MB, less than 12.42% of C++ online submissions for Rearrange Spaces Between Words.

class Solution {
public:
    string reorderSpaces(string text) {
        int words = 0;
        int spaces = 0;
        bool newWordStart = false;
        for (char c : text) 
            if (c == ' ') ++spaces, newWordStart = false;
            else if (!newWordStart) ++words, newWordStart = true;
        
        const int gap = spaces / (words > 1 ? words - 1 : 1);
        newWordStart = false;
        string s;
        for (char c : text) {
            if (c == ' ' && newWordStart) {
                if (spaces >= gap) {
                    s += string(gap, ' ');
                    spaces -= gap;
                } else if (spaces > 0) {
                    s += string(spaces, ' ');
                    spaces = 0;
                }
                newWordStart = false;
            } else if (c != ' ') {
                s += c;
                newWordStart = true;
            }
        }
        if (spaces > 0) s += string(spaces, ' ');
        return s;
    }
};