// 1190. Reverse Substrings Between Each Pair of Parentheses

// Runtime: 4 ms, faster than 39.51% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");
        for (const char& c : s) {
            if (c == '(') {
                stk.push("");
            } else if (c == ')') {
                reverse(begin(stk.top()), end(stk.top()));
                if (stk.size() > 1) {
                    string tmp(stk.top());
                    stk.pop();
                    stk.top() += tmp;
                }
            } else {
                stk.top() += c;
            }
        }
        return stk.top();
    }
};