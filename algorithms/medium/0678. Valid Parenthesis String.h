// 678. Valid Parenthesis String

// Runtime: 1340 ms, faster than 5.01% of C++ online submissions for Valid Parenthesis String.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Valid Parenthesis String.

class Solution {
public:
    bool checkValidString(string s) {
        for (const char& c : s) {
            if (c == '(') ++L;
            else if (c == ')') ++R;
            else ++X;
        }
        if (L + R == 0) return true;
        if (L != R && abs(L - R) > X) return false;
        return check(s);
    }
    
    int L = 0;
    int R = 0;
    int X = 0;
    
    bool check(const string& s, int idx = 0, int lu = 0, int ru = 0, int lxu = 0, int rxu = 0, int exu = 0) {
        // lu = left parenthesis include lxu
        // ru = right parenthesis include rxu
        // lxu + rxu + exu <= X
        // lu + ru + exu <= L + R + X
        
        if (lu < ru) return false;
        if (lu > L + X) return false;
        if (lu == L + X && lu > R) return false;
        if (lxu + rxu + exu > X) return false;
        if (s.length() <= idx) return lu == ru;
        
        if (s[idx] == '(') {
            return check(s, idx + 1, lu + 1, ru, lxu, rxu, exu);
        } else if (s[idx] == ')') {
            if (lu == ru) return false;
            return check(s, idx + 1, lu, ru + 1, lxu, rxu, exu);
        } else {
            return check(s, idx + 1, lu,     ru,     lxu,     rxu,     exu + 1)  // * => empty 
                || check(s, idx + 1, lu + 1, ru,     lxu + 1, rxu,     exu)      // * => (
                || check(s, idx + 1, lu,     ru + 1, lxu,     rxu + 1, exu);     // * => )
        }
    }
};