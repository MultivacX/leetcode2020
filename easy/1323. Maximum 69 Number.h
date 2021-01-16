// 1323. Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
// Memory Usage: 5.7 MB, less than 99.48% of C++ online submissions for Maximum 69 Number.
    
class Solution {
public:
    int maximum69Number (int num) {
        string s(to_string(num));
        int i = 0;
        while (i < s.length() && s[i] == '9') ++i;
        if (i < s.length()) s[i] = '9';
        return stoi(s);
    }
};