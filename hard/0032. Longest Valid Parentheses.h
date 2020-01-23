// 32. Longest Valid Parentheses

// Runtime: 4 ms, faster than 96.05% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 9.8 MB, less than 21.43% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        //cout << s << endl;
        stack<char*> v;
        for (char& c : s) {
            if (c == '(') {
                v.push(&c);
            } else if (!v.empty()) {
                *(v.top()) = '#';
                c = '#';
                v.pop();
            }
        }
        //cout << s << endl;
        
        int ans = 0;
        int cnt = 0;
        for (char c : s) {
            if (c == '#') {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};