// 1417. Reformat The String
// https://leetcode.com/problems/reformat-the-string/

// Runtime: 8 ms, faster than 69.57% of C++ online submissions for Reformat The String.
// Memory Usage: 7.7 MB, less than 5.81% of C++ online submissions for Reformat The String.

class Solution {
public:
    string reformat(string s) {
        string m, n;
        for (char c : s) isdigit(c) ? m += c : n += c; 
        if (m.length() < n.length()) swap(m, n);
        if (m.length() - n.length() > 1) return "";
        
        string t;
        while (t.length() < s.length()) {
            if (!m.empty()) { t += m.back(); m.pop_back(); }
            if (!n.empty()) { t += n.back(); n.pop_back(); }
        }
        return t;
    }
};