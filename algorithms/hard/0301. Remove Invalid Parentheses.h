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


class Solution {
    // int left = 0;
    // int right = 0;
    int mustRemovedLeft = 0; 
    int mustRemovedRight = 0;
    unordered_set<string> strs;
    
    void dfs(const string& s, int i, string& t, int removedLeft, int removedRight, int score) {
        if (i >= s.length()) {
            if (removedLeft == mustRemovedLeft && 
                removedRight == mustRemovedRight &&
                score == 0)
                strs.insert(t);
            return;
        }
        
        if (s[i] == '(') {
            t.push_back(s[i]);
            dfs(s, i + 1, t, removedLeft, removedRight, score + 1);
            t.pop_back();
            
            if (removedLeft < mustRemovedLeft)
                dfs(s, i + 1, t, removedLeft + 1, removedRight, score);
        } else if (s[i] == ')') {
            if (score > 0) {
                t.push_back(s[i]);
                dfs(s, i + 1, t, removedLeft, removedRight, score - 1);
                t.pop_back();
            }
            
            if (removedRight < mustRemovedRight)
                dfs(s, i + 1, t, removedLeft, removedRight + 1, score);
            
        } else {
            t.push_back(s[i]);
            dfs(s, i + 1, t, removedLeft, removedRight, score);
            t.pop_back();
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int score = 0;
        for (char c : s) {
            if (c == '(') {
                // ++left;
                ++score;
            } else if (c == ')') {
                // ++right;
                if(--score < 0) 
                    score = 0, ++mustRemovedRight;
            }
        }
        if (score > 0) mustRemovedLeft = score;
        if (mustRemovedLeft + mustRemovedRight == 0)
            return {s};
        
        string t;
        dfs(s, 0, t, 0, 0, 0);
        return vector<string>(begin(strs), end(strs));
    }
};