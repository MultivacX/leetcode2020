// 186. Reverse Words in a String II
// https://leetcode.com/problems/reverse-words-in-a-string-ii/

// Runtime: 56 ms, faster than 5.75% of C++ online submissions for Reverse Words in a String II.
// Memory Usage: 17.6 MB, less than 65.67% of C++ online submissions for Reverse Words in a String II.
    
class Solution {
public:
    void reverseWords(vector<char>& s) {
        const int N = s.size();
        for (int i = 0, j = 0; i <= N; ++i) {
            if (i == N || s[i] == ' ') {
                reverse(begin(s) + j, begin(s) + i);
                j = i + 1;
            }
        }
        reverse(begin(s), end(s));
    }
};