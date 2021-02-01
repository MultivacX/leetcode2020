// 1249. Minimum Remove to Make Valid Parentheses

// Runtime: 24 ms, faster than 94.81% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 13.4 MB, less than 100.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> parentheses;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                parentheses.push_back(i);
            } else if (s[i] == ')') {
                if (parentheses.empty()) parentheses.push_back(i);
                else if (s[parentheses.back()] == '(') parentheses.pop_back();
                else parentheses.push_back(i);
            }
        }
        
        if (parentheses.empty()) return s;
        
        string ans;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (j < parentheses.size() && parentheses[j] == i) {
                ++j;
                continue;
            }
            
            ans += s[i];
        }
        return ans;
    }
};