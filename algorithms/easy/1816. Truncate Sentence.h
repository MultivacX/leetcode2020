// 1816. Truncate Sentence
// https://leetcode.com/problems/truncate-sentence/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Truncate Sentence.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Truncate Sentence.
    
class Solution {
public:
    string truncateSentence(string s, int k) {
        const int n = s.length();
        for (int i = 0; i < n; ++i) 
            if (s[i] == ' ' && --k == 0) 
                return s.substr(0, i);
        return s;
    }
};