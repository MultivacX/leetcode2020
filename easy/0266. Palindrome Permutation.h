// 266. Palindrome Permutation
// https://leetcode.com/problems/palindrome-permutation/

// Runtime: 4 ms, faster than 6.98% of C++ online submissions for Palindrome Permutation.
// Memory Usage: 6.7 MB, less than 22.86% of C++ online submissions for Palindrome Permutation.
    
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        int oddCnt = 0;
        for (auto it : m) 
            if (it.second & 1) 
                if (++oddCnt > 1) 
                    return false;
        return true;
    }
};