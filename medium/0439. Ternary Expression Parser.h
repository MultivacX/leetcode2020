// 439. Ternary Expression Parser
// https://leetcode.com/problems/ternary-expression-parser/

// Runtime: 8 ms, faster than 62.50% of C++ online submissions for Ternary Expression Parser.
// Memory Usage: 7.1 MB, less than 91.41% of C++ online submissions for Ternary Expression Parser.
    
class Solution {
public:
    string parseTernary(string expression) {
        const int N = expression.length();
        vector<char> stk;
        int i = 0;
        while (i < N) {
            if (i + 1 < N && expression[i + 1] == '?') {
                stk.push_back(expression[i] == 'T' ? 't' : 'f');
                i += 2;
            } else if (expression[i] == ':') {
                ++i;
            } else {
                stk.push_back(expression[i]);
                
                while (stk.size() >= 3) {
                    char b = stk[stk.size() - 3];
                    if (b != 't' && b != 'f') break;
                    char l = stk[stk.size() - 2]; 
                    if (l == 't' || l == 'f') break;
                    char r = stk[stk.size() - 1];
                    
                    stk.pop_back();
                    stk.pop_back();
                    stk.back() = b == 't' ? l : r;
                }
                
                ++i;
            }
        }
        return string(1, stk[0]);
    }
};