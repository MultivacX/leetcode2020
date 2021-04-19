// 1832. Check if the Sentence Is Pangram
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if the Sentence Is Pangram.
// Memory Usage: 6.5 MB, less than 66.67% of C++ online submissions for Check if the Sentence Is Pangram.

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> m(128, 0);
        for (char c : sentence) m[c] = 1;
        return accumulate(begin(m), end(m), 0) == 26;
    }
};