// 772. Basic Calculator III
// https://leetcode.com/problems/basic-calculator-iii/

// Runtime: 16 ms, faster than 16.57% of C++ online submissions for Basic Calculator III.
// Memory Usage: 9.2 MB, less than 31.47% of C++ online submissions for Basic Calculator III.
    
class Solution {
    int checkParentheses(const string& s, int i) {
        // if (s[i] != '(') return i;
        ++i;
        int cnt = 1;
        while (cnt > 0) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            ++i;
        }
        return i;
    }
    
    void multiOrDivide(vector<char>& opts, vector<int>& vals) {
        if (opts.empty()) return;
        
        if (opts.back() == '*') {
            vals[vals.size() - 2] *= vals.back();
            opts.pop_back();
            vals.pop_back();
        } else if (opts.back() == '/') {
            vals[vals.size() - 2] /= vals.back();
            opts.pop_back();
            vals.pop_back();
        }
    }
    
    int calcu(vector<char>& opts, vector<int>& vals) {
        int val = vals[0];
        for (int i = 0; i < opts.size(); ++i) {
            if (opts[i] == '+') val += vals[i + 1];
            else if (opts[i] == '-') val -= vals[i + 1];
        }
        return val;
    }

public:
    int calculate(string s) {
        const int N = s.length();
        vector<char> opts;
        vector<int> vals;
        int i = 0;
        while (i < N) {
            if (s[i] == '(') {
                int j = checkParentheses(s, i);
                vals.push_back(calculate(s.substr(i + 1, j - 2 - i)));
                multiOrDivide(opts, vals);
                i = j;
            } else if (isdigit(s[i])) {
                int v = 0;
                while (i < N && isdigit(s[i])) 
                    v = v * 10 + s[i++] - '0';
                vals.push_back(v);
                multiOrDivide(opts, vals);
            } else if (string("+-*/").find(s[i]) != string::npos) {
                opts.push_back(s[i]);
                ++i;
            } else {
                ++i;
            }
        }
        return calcu(opts, vals);
    }
};