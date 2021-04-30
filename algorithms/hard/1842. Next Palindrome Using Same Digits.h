// 1842. Next Palindrome Using Same Digits
// https://leetcode.com/problems/next-palindrome-using-same-digits/

// Runtime: 20 ms, faster than 100.00% of C++ online submissions for Next Palindrome Using Same Digits.
// Memory Usage: 13 MB, less than 100.00% of C++ online submissions for Next Palindrome Using Same Digits.
    
class Solution {
public:
    string nextPalindrome(string num) {
        const int n = num.size();
        
        string s(num.substr(0, n / 2));
        if (!next_permutation(begin(s), end(s)))
            return "";
        
        string t(s);
        reverse(begin(t), end(t));
        if (n & 1) return s + num[n / 2] + t;
        return s + t;
    }
};