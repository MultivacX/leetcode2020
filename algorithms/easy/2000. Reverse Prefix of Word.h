// 2000. Reverse Prefix of Word
// https://leetcode.com/problems/reverse-prefix-of-word/

// Runtime: 3 ms, faster than 35.70% of C++ online submissions for Reverse Prefix of Word.
// Memory Usage: 6.1 MB, less than 73.15% of C++ online submissions for Reverse Prefix of Word.
    
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(begin(word), begin(word) + p + 1);
        return word;
    }
};