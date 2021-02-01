// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/

// Runtime: 4 ms, faster than 39.14% of C++ online submissions for Minimum Add to Make Parentheses Valid.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Minimum Add to Make Parentheses Valid.

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for (const char& c : S) {
            if (s.empty() || s.top() == ')' || c == '(') s.push(c);
            else s.pop();
        }
        return s.size();
    }
};