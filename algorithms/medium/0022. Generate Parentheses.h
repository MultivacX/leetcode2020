// 22. Generate Parentheses

// Runtime: 4 ms, faster than 87.99% of C++ online submissions for Generate Parentheses.
// Memory Usage: 13.7 MB, less than 88.43% of C++ online submissions for Generate Parentheses.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {""};
        
        int l = n;
        int r = n;
        string s;
        vector<string> ans;
        gen(l, r, s, ans);
        return ans;
    }
    
    void gen(int l, int r, string& s, vector<string>& ans) {
        if (r == 0) {
            ans.push_back(s);
            return;
        }
        
        if (l == r) {
            s.append("(");
            gen(l - 1, r, s, ans);
            s.pop_back();
        } else if (l < r) {
            if (l == 0) {
                s.append(")");
                gen(l, r - 1, s, ans);
                s.pop_back();
            } else {
                s.append("(");
                gen(l - 1, r, s, ans);
                s.pop_back();
                
                s.append(")");
                gen(l, r - 1, s, ans);
                s.pop_back();
            }
        }
    }
};


class Solution {
    vector<string> ans;
    
    void helper(const int n, int l, int r, string& s) {
        if (n * 2 == l + r) {
            ans.push_back(s);
            return;
        }
        
        if (l < n) {
            s.push_back('(');
            helper(n, l + 1, r, s);
            s.pop_back();
        }
        if (l > r) {
            s.push_back(')');
            helper(n, l, r + 1, s);
            s.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string s;
        helper(n, 0, 0, s);
        return ans;
    }
};