// 1616. Split Two Strings to Make Palindrome
// https://leetcode.com/problems/split-two-strings-to-make-palindrome/

// Runtime: 76 ms, faster than 94.71% of C++ online submissions for Split Two Strings to Make Palindrome.
// Memory Usage: 24.5 MB, less than 5.02% of C++ online submissions for Split Two Strings to Make Palindrome.

class Solution {
    bool isPalindrome(const string& a, int i = 0, int j = -1) {
        if (j < 0) j = (int)a.length() - 1;
        while (i < j)
            if (a[i++] != a[j--]) 
                return false;
        return true;
    }
    
    bool isPalindrome(const string& a, const string& b) {
        const int M = a.length();
        int i = 0;
        int j = M - 1;
        while (i < M) {
            if (a[i] == b[j]) {
                ++i;
                --j;
                if (i >= j) return true;
            } else {
                return isPalindrome(a, i, j) || isPalindrome(b, i, j);
            }
        }
        return true;
    }
    
public:
    bool checkPalindromeFormation(string a, string b) {
        return isPalindrome(a) || isPalindrome(b) || isPalindrome(a, b) || isPalindrome(b, a);
    }
};