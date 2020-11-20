// 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Replace All ?'s to Avoid Consecutive Repeating Characters.
// Memory Usage: 6.3 MB, less than 7.73% of C++ online submissions for Replace All ?'s to Avoid Consecutive Repeating Characters.

class Solution {
public:
    string modifyString(string s) {
        const int N = s.length();
        for (int i = 0; i < N; ++i) {
            if (s[i] != '?') continue;
            char l = i > 0 ? s[i - 1] : '#';
            char r = i + 1 < N ? s[i + 1] : '#';
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == l || c == r) continue;
                s[i] = c;
                break;
            }
        }
        return s;
    }
};