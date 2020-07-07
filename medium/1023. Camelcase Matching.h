// 1023. Camelcase Matching
// https://leetcode.com/problems/camelcase-matching/

// Runtime: 4 ms, faster than 50.49% of C++ online submissions for Camelcase Matching.
// Memory Usage: 7.3 MB, less than 49.58% of C++ online submissions for Camelcase Matching.

class Solution {
    bool isLowercase(char c) {
        return c >= 'a' && c <= 'z';
    }
    
    bool match(const string& s, const string& p) {
        const int m = s.length();
        const int n = p.length();
        if (m < n) return false;
        if (m == n) return s == p;
        
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (isLowercase(s[i])) {
                if (isLowercase(p[j]) && s[i] == p[j]) ++j;
                ++i;
            } else {
                if (isLowercase(p[j]) || s[i] != p[j]) return false;
                ++i;
                ++j;
            }
        }
        
        while (i < m) {
            if (!isLowercase(s[i++])) 
                return false;
        }
        return j >= n;
    }
    
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        const int n = queries.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = match(queries[i], pattern);
        return ans;
    }
};