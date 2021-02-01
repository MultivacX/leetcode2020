// 301. Remove Invalid Parentheses

// Runtime: 196 ms, faster than 12.43% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 25.8 MB, less than 8.33% of C++ online submissions for Remove Invalid Parentheses.

class Solution {
public:
    vector<string> ans;
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<int, unordered_set<string>> m{{0, {s}}};
        int level = 0;
        while (!m[level].empty()) {
            for (const auto& str : m[level]) {
                if (isValid(str)) ans.push_back(str);
            }
            if (!ans.empty()) break;
            for (const auto& str : m[level]) {
                for (int i = 0; i < str.length(); ++ i) {
                    string ss(str);
                    ss.erase(ss.begin() + i);
                    m[level + 1].insert(ss);
                }
            }
            m.erase(level);
            ++level;
        }
        return ans;
    }
    
    bool isValid(const string& s) {
        int left = 0;
        for (char c : s) {
            if (c == '(') ++left;
            else if (c == ')') --left;
            if (left < 0) return false;
        }
        return left == 0;
    }
};