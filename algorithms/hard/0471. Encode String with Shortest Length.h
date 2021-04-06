// 471. Encode String with Shortest Length
// https://leetcode.com/problems/encode-string-with-shortest-length/

// Runtime: 408 ms, faster than 16.08% of C++ online submissions for Encode String with Shortest Length.
// Memory Usage: 87.4 MB, less than 16.52% of C++ online submissions for Encode String with Shortest Length.
    
class Solution {
    unordered_map<string, string> memo;
    
    pair<int, string> encode1(const string& s) {
        const int n = s.length();
        if (n <= 4) return {1, s};
        
        string s2(s + s);
        auto i = s2.find(s, 1);
        if (i == string::npos) return {1, s};
        
        return {n / i, s.substr(0, i)};
    }
    
public:
    string encode(string s) {
        const int n = s.length();
        if (n <= 4) return s;
        if (memo.count(s)) return memo[s];
        
        auto [k, str] = encode1(s);
        string t = k == 1 ? s : to_string(k) + "[" + encode(str) + "]";
        
        for (int l = 1; l < n; ++l) {
            string c(encode(s.substr(0, l)) + encode(s.substr(l)));
            if (c.length() < t.length()) t = move(c);
        }
        
        memo[s] = t;
        return memo[s];
    }
};