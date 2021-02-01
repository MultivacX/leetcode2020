// 917. Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
// Memory Usage: 6.2 MB, less than 88.68% of C++ online submissions for Reverse Only Letters.
    
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = (int)S.length() - 1;
        while (i < j) 
            if (!isalpha(S[i])) ++i;
            else if (!isalpha(S[j])) --j;
            else swap(S[i++], S[j--]);
        return S;
    }
};