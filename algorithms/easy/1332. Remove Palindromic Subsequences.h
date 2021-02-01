// 1332. Remove Palindromic Subsequences
// https://leetcode.com/problems/remove-palindromic-subsequences/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Palindromic Subsequences.
// Memory Usage: 6.1 MB, less than 96.39% of C++ online submissions for Remove Palindromic Subsequences.
    
class Solution {
public:
    int removePalindromeSub(string s) {
        const int N = s.length();
        if (N <= 1) return 0;
        int l = 0, r = N - 1;
        while (l <= r && s[l] == s[r]) 
            ++l, --r;
        return l >= r ? 1 : 2;
    }
};