// 481. Magical String
// https://leetcode.com/problems/magical-string/

// Runtime: 8 ms, faster than 86.52% of C++ online submissions for Magical String.
// Memory Usage: 8 MB, less than 70.92% of C++ online submissions for Magical String.

class Solution {
public:
    int magicalString(int n) {
        // https://en.wikipedia.org/wiki/Kolakoski_sequence
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        string s("122");
        int cnt = 1;
        int i = 3;
        while (s.length() < n) {
            char c = s[i - 1];
            char t = i & 1 ? '1' : '2';
            s += t;
            if (c == '2') s += t;
            if (c == '1') ++cnt;
            ++i;
        }
        // cout << s;
        while (i <= n) if (s[(i++) - 1] == '1') ++cnt;
        return cnt;
    }
};