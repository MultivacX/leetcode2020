// 20. Valid Parentheses

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (stk.empty()) {
                return false;
            } else if (c == ')' && stk.top() != '(') {
                return false;
            } else if (c == ']' && stk.top() != '[') {
                return false;
            } else if (c == '}' && stk.top() != '{') {
                return false;
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (char c : s) {
            if (c == '(') t.push(c);
            else if (c == '[') t.push(c);
            else if (c == '{') t.push(c);
            else if (c == ')') { 
                if (t.empty() || t.top() != '(') 
                    return false; 
                t.pop();
            }
            else if (c == ']') { 
                if (t.empty() || t.top() != '[') 
                    return false; 
                t.pop();
            }
            else if (c == '}') { 
                if (t.empty() || t.top() != '{') 
                    return false; 
                t.pop();
            }
        }
        return t.empty();
    }
};