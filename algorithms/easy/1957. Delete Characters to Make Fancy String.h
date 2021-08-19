// 1957. Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

// Runtime: 144 ms, faster than 61.32% of C++ online submissions for Delete Characters to Make Fancy String.
// Memory Usage: 41.1 MB, less than 68.84% of C++ online submissions for Delete Characters to Make Fancy String.
    
class Solution {
public:
    string makeFancyString(string s) {
        string p;
        for (int i = 0; i < s.length(); ++i) {
            const int n = p.length();
            if (n < 2) {
                p += s[i];
            } else if (p[n - 2] == p[n - 1] && p[n - 1] == s[i]) {
                // cout << p << endl;
            } else {
                p += s[i];
            }
        }
        return p;
    }
};