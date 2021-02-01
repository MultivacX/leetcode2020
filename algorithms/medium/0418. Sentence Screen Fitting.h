// 418. Sentence Screen Fitting
// https://leetcode.com/problems/sentence-screen-fitting/

// Runtime: 28 ms, faster than 47.56% of C++ online submissions for Sentence Screen Fitting.
// Memory Usage: 7.4 MB, less than 99.19% of C++ online submissions for Sentence Screen Fitting.
    
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        const int N = sentence.size();
        // {i, k}: sentence[i] ... sentence[i+k-1] in 1 row
        unordered_map<int, int> m;
        int i = 0, words = 0;
        while (rows-- > 0) {
            if (m.count(i) == 0) {
                int j = i, k = 0;
                int l = sentence[j].length();
                while (l <= cols) {
                    j = (j + 1) % N;
                    ++k;
                    l += 1 + sentence[j].length();
                }
                m[i] = k;
            }
            words += m[i];
            i = (i + m[i]) % N;
        }
        return words / N;
    }
};