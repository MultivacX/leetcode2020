// 1763. Longest Nice Substring
// https://leetcode.com/problems/longest-nice-substring/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Nice Substring.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Longest Nice Substring.
    
class Solution {
public:
    string longestNiceSubstring(string s) {
        // cout << s << endl;
        const int n = s.length();
        if (n < 2) return "";
        
        vector<int> a(26, 0);
        vector<int> A(26, 0);
        for (char c : s) 
            if ('a' <= c && c <= 'z') ++a[c - 'a'];
            else ++A[c - 'A'];
        unordered_set<char> x;
        for (int i = 0; i < 26; ++i)
            if ((a[i] == 0 || A[i] == 0) && a[i] + A[i] > 0)
                x.insert('a' + i), x.insert('A' + i);
        if (x.empty()) return s;
        
        string ans;
        for (int i = 0, l = -1; i < n; ++i) {
            bool bad = x.count(s[i]);
            if (!bad && l == -1) l = i;
            
            if (bad || i + 1 == n) {
                if (l == -1) continue;
                int len = (bad ? i - 1 : i) - l + 1;
                if (len > 1) {
                    string t = longestNiceSubstring(s.substr(l, len));
                    if (ans.length() < t.length()) ans = t;
                }
                l = -1;
            }
        }
        return ans;
    }
};