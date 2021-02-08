// 1754. Largest Merge Of Two Strings
// https://leetcode.com/problems/largest-merge-of-two-strings/

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Largest Merge Of Two Strings.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Largest Merge Of Two Strings.
    
class Solution {
public:
    string largestMerge(string word1, string word2) {
        const int l1 = word1.length();
        const int l2 = word2.length();
        int i1 = 0, i2 = 0;
        string m;
        while (i1 < l1 && i2 < l2) {
            if (word1[i1] == word2[i2]) {
                // word1[i1...j1-1] == word2[i2...j2-1]
                int j1 = i1 + 1, j2 = i2 + 1;
                while (j1 < l1 && j2 < l2 && word1[j1] == word2[j2]) 
                    ++j1, ++j2;
                
                bool adv1 = true;
                if (j1 == l1 && j2 == l2) adv1 = true;
                else if (j1 == l1) adv1 = false;
                else if (j2 == l2) adv1 = true;    
                else if (word1[j1] > word2[j2]) adv1 = true;
                else adv1 = false;
                
                if (adv1) {
                    m += word1[i1++];
                    while (i1 < l1 && word1[i1 - 1] == word1[i1]) 
                        m += word1[i1++];
                } else {
                    m += word2[i2++];
                    while (i2 < l2 && word2[i2 - 1] == word2[i2]) 
                        m += word2[i2++];
                }
            }
            else if (word1[i1] > word2[i2]) m += word1[i1++];
            else m += word2[i2++];
        }
        if (i1 < l1) m += word1.substr(i1);
        if (i2 < l2) m += word2.substr(i2);
        return m;
    }
};