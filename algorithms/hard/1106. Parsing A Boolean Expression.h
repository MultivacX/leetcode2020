// 1106. Parsing A Boolean Expression
// https://leetcode.com/problems/parsing-a-boolean-expression/

// Runtime: 4 ms, faster than 97.25% of C++ online submissions for Parsing A Boolean Expression.
// Memory Usage: 7.6 MB, less than 5.05% of C++ online submissions for Parsing A Boolean Expression.

class Solution {
    bool eval(const array<int, 3>& arr) {
        int op = arr[0];
        int cnt_t = arr[1];
        int cnt_f = arr[2];
        if (op == '!') return cnt_f > 0;
        if (op == '&') return cnt_f == 0;
        /* op == '|' */return cnt_t > 0;
    }
    
public:
    bool parseBoolExpr(string expression) {
        const int N = expression.length();
        if (N == 1) return expression == "t";
        
        // {op, cnt_t, cnt_f}
        stack<array<int, 3>> s;
        int i = 0;
        while (i < N) {
            switch (expression[i]) {
                case '!':
                case '&':
                case '|':
                    s.push({expression[i++], 0, 0});
                    break;
                case ')': {
                    bool b = eval(s.top()); s.pop();
                    if (!s.empty()) ++s.top()[b ? 1 : 2];
                    else return b;
                }
                    break;
                case 't':
                    ++s.top()[1];
                    break;
                case 'f':
                    ++s.top()[2];
                    break;
            }
            ++i;
        }
        return eval(s.top());
    }
};