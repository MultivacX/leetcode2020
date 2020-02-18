// 151. Reverse Words in a String

// Runtime: 8 ms, faster than 77.99% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 9.7 MB, less than 91.89% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ' && i > 0 && s[i - 1] != ' ') {
                reverse(s.begin() + start, s.begin() + i);
                while (start < i && s[start] != ' ') {
                    ++start;
                }
                ++start;
            } else if (s[i] != ' ' && i == s.length() - 1) {
                reverse(s.begin() + start, s.end());
            }
        }
        while (!s.empty() && s.back() == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};