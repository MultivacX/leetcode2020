// 1768. Merge Strings Alternately
// https://leetcode.com/problems/merge-strings-alternately/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Strings Alternately.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Merge Strings Alternately.
    
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        string w;
        while (i < m && j < n) {
            w += word1[i++];
            w += word2[j++];
        }
        if (i < m) w += word1.substr(i);
        if (j < n) w += word2.substr(j);
        return w;
    }
};