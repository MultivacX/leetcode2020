// 722. Remove Comments

// Runtime: 4 ms, faster than 46.10% of C++ online submissions for Remove Comments.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Remove Comments.

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        
        bool blockStart = false;
        bool hasContentBeforeBlockStart = false;
        for (const string& s : source) {
            string t;
        
            bool bStart = false;
            bool bEnd = false;
            for (int i = 0; i < s.length(); ++i) {
                if (blockStart) {
                    if (s[i] == '*' && i + 1 < s.length() && s[i + 1] == '/') {
                        blockStart = false;
                        bEnd = true;
                        ++i;
                    }
                } else if (s[i] == '/' && i + 1 < s.length() && s[i + 1] == '*') {
                    hasContentBeforeBlockStart = !t.empty();
                    blockStart = true;
                    bStart = true;
                    ++i;
                } else if (s[i] == '/' && i + 1 < s.length() && s[i + 1] == '/') {
                    break;
                } else {
                    t += s[i];
                }
            }
            
            if (bEnd) { // a block comment ended
                if (bStart) { // a block comment in 1 line
                    if (!t.empty()) ans.push_back(t);
                } else { // a block comment crossing lines
                    if (hasContentBeforeBlockStart && !ans.empty()) ans.back() += t;
                    hasContentBeforeBlockStart = false;
                }
            } else if (!t.empty()) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};