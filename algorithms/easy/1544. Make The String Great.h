// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Make The String Great.
// Memory Usage: 6.6 MB, less than 6.85% of C++ online submissions for Make The String Great.

class Solution {
public:
    string makeGood(string s) {
        string t;
        t += s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (!t.empty() && tolower(t.back()) == tolower(s[i]) && t.back() != s[i])
                t.pop_back();
            else t += s[i];
        }
        return t;
    }
};