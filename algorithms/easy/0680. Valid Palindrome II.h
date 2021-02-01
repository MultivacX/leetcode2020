// 680. Valid Palindrome II

// Runtime: 332 ms, faster than 5.10% of C++ online submissions for Valid Palindrome II.
// Memory Usage: 19.8 MB, less than 100.00% of C++ online submissions for Valid Palindrome II.

// Time Complexity: O(s.length()).
// Space Complexity: O(1).

class Solution {
    bool validPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = (int)s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
                continue;
            }
            return validPalindrome(s, i + 1, j) || validPalindrome(s, i, j - 1);
        }
        return true;
    }
};