// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// Runtime: 4 ms, faster than 11.55% of C++ online submissions for Maximum Nesting Depth of the Parentheses.
// Memory Usage: 6.1 MB, less than 96.63% of C++ online submissions for Maximum Nesting Depth of the Parentheses.
    
class Solution {
public:
    int maxDepth(string s) {
        int d = 0, t = 0;
        for (char c : s) {
            if (c == '(') d = max(d, ++t);
            else if (c == ')') --t;
        }
        return d;
    }
};