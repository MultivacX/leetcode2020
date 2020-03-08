// 504. Base 7

// Runtime: 12 ms, faster than 49.09% of C++ online submissions for Base 7.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Base 7.

class Solution {
public:
    string convertToBase7(int num) {
        string s;
        bool negative = num < 0;
        if (negative) num *= -1;
        while (num) {
            s += (char)(num % 7 + '0');
            num /= 7;
        }
        if (s.empty()) return "0";
        if (negative) s += '-';
        reverse(s.begin(), s.end());
        return s;
    }
};