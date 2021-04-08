// 1813. Sentence Similarity III
// https://leetcode.com/problems/sentence-similarity-iii/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sentence Similarity III.
// Memory Usage: 6.2 MB, less than 93.45% of C++ online submissions for Sentence Similarity III.
    
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int m = sentence1.length();
        int n = sentence2.length();
        if (m == n) return sentence1 == sentence2;
        if (m == 0 || n == 0) return true;
        
        if (m > n) swap(sentence1, sentence2), swap(m, n);
        
        // auto i = sentence2.find(sentence1);
        // // "A" ~ "A B"
        // if (i == 0) return sentence2[m] == ' ';
        // // "B" ~ "A B"
        // if (i == n - m) return sentence2[i - 1] == ' ';
        
        int i1 = 0, j1 = m - 1;
        int i2 = 0, j2 = n - 1;
        
        while (i1 < m && sentence1[i1] == sentence2[i2]) 
            ++i1, ++i2;
        // "A" ~ "A B"
        if (i1 >= m && sentence2[m] == ' ') return true;
        
        while (j1 >= 0 && sentence1[j1] == sentence2[j2]) 
            --j1, --j2;
        // "B" ~ "A B"
        if (j1 < 0 && sentence2[n - m - 1] == ' ') return true;
        
        if (i1 >= m || j1 < 0) return false;
        if (i1 < j1) return false;
        
        return i2 > 0 && j2 < n - 1 && sentence2[i2 - 1] == ' ' && sentence2[j2 + 1] == ' ';
    }
};