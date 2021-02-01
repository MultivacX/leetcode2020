// 1541. Minimum Insertions to Balance a Parentheses String
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

// Runtime: 104 ms, faster than 61.16% of C++ online submissions for Minimum Insertions to Balance a Parentheses String.
// Memory Usage: 14.8 MB, less than 18.01% of C++ online submissions for Minimum Insertions to Balance a Parentheses String.

class Solution {
public:
    int minInsertions(string s) {
        const int N = s.length();
        int ans = 0;
        stack<int> st;
        int i = 0;
        while (i < N) {
            if (s[i] == '(') {
                st.push(1);
                ++i;
            } else if (i + 1 < N && s[i + 1] == ')') {
                if (st.empty()) ++ans;    
                else st.pop();
                i += 2;
            } else { // i + 1 == N || s[i + 1] == '('
                if (st.empty()) ans += 2;
                else st.pop(), ++ans;
                ++i;
            }
        }
        return ans + st.size() * 2;
    }
};