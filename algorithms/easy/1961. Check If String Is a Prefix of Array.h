// 1961. Check If String Is a Prefix of Array
// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

// Runtime: 4 ms, faster than 80.65% of C++ online submissions for Check If String Is a Prefix of Array.
// Memory Usage: 13.8 MB, less than 91.05% of C++ online submissions for Check If String Is a Prefix of Array.
    
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        const int n = s.length();
        int i = 0;
        for (const auto& w : words) {
            int j = 0;
            for (; j < w.length() && i < n; ++i, ++j) 
                if (s[i] != w[j]) return false;
            if (i == n) return j == w.length();
        }
        return false;
    }
};