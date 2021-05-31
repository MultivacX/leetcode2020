// 1880. Check if Word Equals Summation of Two Words
// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Word Equals Summation of Two Words.
// Memory Usage: 5.8 MB, less than 66.67% of C++ online submissions for Check if Word Equals Summation of Two Words.
    
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1 = 0; 
        for (char c : firstWord)
            n1 = n1 * 10 + c - 'a';
        
        int n2 = 0; 
        for (char c : secondWord)
            n2 = n2 * 10 + c - 'a';
        
        int n3 = 0; 
        for (char c : targetWord)
            n3 = n3 * 10 + c - 'a';
        
        return n1 + n2 == n3;
    }
};