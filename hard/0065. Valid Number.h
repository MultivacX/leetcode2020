// 65. Valid Number

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Number.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Valid Number.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    bool isNumber(string s) {
        const int N = s.length();
        if (N == 0) return false;
        
        int i = 0;
        
        // skip space
        while (i < N && s[i] == ' ') ++i;
        if (i >= N) return false;
        
        // before e
        int sign = -1;
        int point = -1;
        int num = -1;
        while (i < N && s[i] != 'e') {
            if (s[i] == '+' || s[i] == '-') {
                if (sign >= 0) return false;
                sign = i;
                if (point >= 0 && point < sign) return false;
                if (num >= 0 && num < sign) return false;
            } else if (s[i] == '.') {
                if (point >= 0) return false;
                point = i;
            } else if (isdigit(s[i])) {
                if (num < 0) num = i;
            } else if (s[i] == ' ') {
                if (num < 0) return false;
                // skip space
                while (i < N && s[i] == ' ') ++i;
                return i >= N;
            } else {
                return false;
            }
            ++i;
        }
        
        if (num < 0) return false;
        if (i >= N) return true;
        
        // skip e
        ++i;
        if (i >= N) return false;
        
        sign = -1;
        num = -1;
        while (i < N) {
            if (s[i] == '+' || s[i] == '-') {
                if (sign >= 0) return false;
                sign = i;
                if (num >= 0 && num < sign) return false;
            } else if (isdigit(s[i])) {
                if (num < 0) num = i;
            } else if (s[i] == ' ') {
                if (num < 0) return false;
                // skip space
                while (i < N && s[i] == ' ') ++i;
                return i >= N;
            } else {
                return false;
            }
            ++i;
        }
        return num > 0;
    }
};