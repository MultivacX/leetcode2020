// 171. Excel Sheet Column Number

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Excel Sheet Column Number.

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        // const int N = s.length();
        for (const char& c : s) {
            num *= 26;
            num += c - 'A' + 1;
        }
        return num;
    }
};


class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char c : s)
            ans = ans * 26 - 'A' + c + 1;
        return ans;
    }
};