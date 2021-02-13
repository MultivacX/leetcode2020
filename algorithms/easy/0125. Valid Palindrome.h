// 125. Valid Palindrome

// Runtime: 12 ms, faster than 50.41% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Valid Palindrome.

// Time Complexity: O(s.length()).
// Space Complexity: O(1).

class Solution {
    char get_alnum(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        return c;
    }
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = (int)s.length() - 1;
        while (i <= j) {
            if (!isalnum(s[i])) { ++i; continue; }
            if (!isalnum(s[j])) { --j; continue; }
            if (get_alnum(s[i]) != get_alnum(s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.length() - 1;
        while (i < j) {
            if (!isalnum(s[i])) ++i;
            else if (!isalnum(s[j])) --j;
            else if (isdigit(s[i]) && isdigit(s[j]) && s[i] == s[j]) ++i, --j;
            else if (isalpha(s[i]) && isalpha(s[j]) && tolower(s[i]) == tolower(s[j])) ++i, --j;
            else return false;
        }
        return true;
    }
};