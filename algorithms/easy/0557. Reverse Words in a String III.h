// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

// Runtime: 20 ms, faster than 75.93% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 9.9 MB, less than 89.30% of C++ online submissions for Reverse Words in a String III.
    
class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();
        for (int i = 0, j = 0; j < N; ++j) {
            if (s[j] == ' ' || j + 1 == N) {
                reverse(begin(s) + i, j + 1 == N ? end(s) : begin(s) + j);
                i = j + 1;
            }
        }
        return s;
    }
};