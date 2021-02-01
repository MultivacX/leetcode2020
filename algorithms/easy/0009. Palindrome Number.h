// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

// Runtime: 4 ms, faster than 95.86% of C++ online submissions for Palindrome Number.
// Memory Usage: 6.1 MB, less than 9.44% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s(to_string(x));
        int i = 0;
        int j = s.length() - 1;
        while (i < j) 
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};