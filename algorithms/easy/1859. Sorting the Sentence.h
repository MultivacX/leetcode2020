// 1859. Sorting the Sentence
// https://leetcode.com/problems/sorting-the-sentence/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sorting the Sentence.
// Memory Usage: 6.3 MB, less than 33.33% of C++ online submissions for Sorting the Sentence.
    
class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(9);
        int i = 0;
        while (i < s.length()) {
            string t;
            while (i < s.length() && s[i] != ' ') {
                t += s[i];
                ++i;
            }
            ++i;
            int j = t.back() - '1';
            t.pop_back();
            v[j] = t;
        }
        
        string t;
        for (int i = 0; i < 9; ++i) {
            if (v[i].empty()) break;
            t += v[i];
            if (i + 1 < 9 && !v[i + 1].empty())
                t += ' ';
        }
        return t;
    }
};
