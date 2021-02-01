// 408. Valid Word Abbreviation
// https://leetcode.com/problems/valid-word-abbreviation/

// Runtime: 556 ms, faster than 5.00% of C++ online submissions for Valid Word Abbreviation.
// Memory Usage: 6.2 MB, less than 83.75% of C++ online submissions for Valid Word Abbreviation.
    
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const int m = word.length();
        const int n = abbr.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (!isdigit(abbr[j])) {
                if (word[i] == abbr[j]) ++i, ++j;
                else return false;
                continue;
            } else if (abbr[j] == '0') {
                return false;
            }
            int k = 0;
            while (j < n && isdigit(abbr[j]))
                k = k * 10 + abbr[j++] - '0';
            while (k-- > 0) ++i;
        }
        return i == m && j == n;
    }
};