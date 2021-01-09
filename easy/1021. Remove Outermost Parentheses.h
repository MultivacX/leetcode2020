// 1021. Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/

// Runtime: 4 ms, faster than 73.74% of C++ online submissions for Remove Outermost Parentheses.
// Memory Usage: 7 MB, less than 75.69% of C++ online submissions for Remove Outermost Parentheses.
    
class Solution {
public:
    string removeOuterParentheses(string S) {
        string T;
        string s;
        for (char c : S) {
            if (s.empty()) {
                s += c;
            } else if (c == '(') {
                s += c;
                T += c;
            } else {
                s.pop_back();
                if (!s.empty()) T += c;
            }
        }
        return T;
    }
};