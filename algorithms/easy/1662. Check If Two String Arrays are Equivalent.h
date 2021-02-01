// 1662. Check If Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// Runtime: 4 ms, faster than 88.39% of C++ online submissions for Check If Two String Arrays are Equivalent.
// Memory Usage: 11.7 MB, less than 69.04% of C++ online submissions for Check If Two String Arrays are Equivalent.
    
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, i2 = 0;
        int j1 = 0, j2 = 0;
        while (i1 < word1.size() && i2 < word2.size()) {
            if (j1 == word1[i1].length()) { ++i1; j1 = 0; }
            if (j2 == word2[i2].length()) { ++i2; j2 = 0; }
            
            // if (i1 < word1.size() && 
            //     i2 < word2.size() &&
            //     j1 < word1[i1].length() &&
            //     j2 < word2[i2].length())
            //     cout << word1[i1][j1] << "  " << word2[i2][j2] << endl;
            
            if (i1 < word1.size() && 
                i2 < word2.size() &&
                j1 < word1[i1].length() &&
                j2 < word2[i2].length() &&
                word1[i1][j1++] != word2[i2][j2++]) {
                // cout << word1[i1][j1-1] << "  " << word2[i2][j2-1] << endl;
                return false;
            }
        }
        return i1 == word1.size() && 
               i2 == word2.size() &&
               j1 == 0 &&
               j2 == 0;
    }
};