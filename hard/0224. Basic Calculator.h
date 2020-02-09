// 224. Basic Calculator

// Runtime: 12 ms, faster than 88.82% of C++ online submissions for Basic Calculator.
// Memory Usage: 10.4 MB, less than 90.48% of C++ online submissions for Basic Calculator.

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return calculate(s, i);
    }
    
    int calculate(const string& s, int& i) {
        int ans = 0;
        char sign = '+';
        while (i < s.length()) {
            if (s[i] == ' ') {
                ++i;
            } else if (s[i] == '(') {
                ans += (sign == '-' ? -1 : 1) * calculate(s, ++i);
                sign = '+';
            } else if (s[i] == ')') {
                ++i;
                break;
            } else if (s[i] == '+') {
                ++i;
                sign = '+';
            } else if (s[i] == '-') {
                ++i;
                sign = '-';
            } else {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                ans += (sign == '-' ? -1 : 1) * num;
                sign = '+';
            }
        }
        return ans;
    }
};