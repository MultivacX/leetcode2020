// 856. Score of Parentheses

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Score of Parentheses.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Score of Parentheses.

class Solution {
public:
    int scoreOfParentheses(string S) {
        int i = 0;
        return scoreOfParentheses(S, i);
    }
    
    int scoreOfParentheses(const string& S, int& i) {
        int ans = 0;
        while (i < S.length()) {
            if (S[i] == '(') {
                ++i;
                if (S[i] == ')') {
                    ans += 1;
                } else {
                    ans += 2 * scoreOfParentheses(S, i);
                }
                ++i;
            } else {
                break;
            }
        }
        return ans;
    }
};