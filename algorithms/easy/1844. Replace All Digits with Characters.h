// 1844. Replace All Digits with Characters
// https://leetcode.com/problems/replace-all-digits-with-characters/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Replace All Digits with Characters.
// Memory Usage: 6.1 MB, less than 20.00% of C++ online submissions for Replace All Digits with Characters.
    
class Solution {
public:
    string replaceDigits(string s) {
        const int n = s.length();
        for (int i = 1; i < n; i += 2)
            s[i] = s[i - 1] + s[i] - '0';
        return s;
    }
};