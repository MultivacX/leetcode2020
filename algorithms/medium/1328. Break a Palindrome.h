// 1328. Break a Palindrome

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Break a Palindrome.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Break a Palindrome.

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() == 1) return "";
        
        const int N = palindrome.length();
        bool replaced = false;
        for (int i = 0; i < N && !replaced; ++i) {
            if (palindrome[i] != 'a') {
                if ((N & 1) && i == N / 2) continue;
                palindrome[i] = 'a';
                replaced = true;
            }
        }
        if (!replaced) palindrome.back() = 'b';
        return palindrome;
    }
};