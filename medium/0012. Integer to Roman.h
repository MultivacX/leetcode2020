// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

// Runtime: 8 ms, faster than 87.99% of C++ online submissions for Integer to Roman.
// Memory Usage: 6.1 MB, less than 71.14% of C++ online submissions for Integer to Roman.

class Solution {
public:
    string intToRoman(int num) {
        // string r;
        // int N = 1000;
        // if (num >= N) {
        //     static const vector<string> R{"", "M", "MM", "MMM"};
        //     r += R[num / N];
        //     num %= N;
        // }
        // N /= 10;
        // if (num >= N) {
        //     static const vector<string> R{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        //     r += R[num / N];
        //     num %= N;
        // }
        // N /= 10;
        // if (num >= N) {
        //     static const vector<string> R{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        //     r += R[num / N];
        //     num %= N;
        // }
        // N /= 10;
        // if (num >= N) {
        //     static const vector<string> R{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        //     r += R[num / N];
        //     num %= N;
        // }
        // N /= 10;
        // return r;
        
        static const vector<vector<string>> R{
            {"", "M", "MM", "MMM"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
        };
        string r;
        int N = 1000;
        int i = 0;
        while (num > 0) {
            if (num >= N) {
                r += R[i][num / N];
                num %= N;
            }
            N /= 10;
            ++i;
        }
        return r;
    }
};