// 1271. Hexspeak
// https://leetcode.com/problems/hexspeak/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hexspeak.
// Memory Usage: 6.4 MB, less than 58.06% of C++ online submissions for Hexspeak.
    
class Solution {
public:
    string toHexspeak(string num) {
        static const string H = "OI23456789ABCDEF";
        auto n = stoull(num);
        string h;
        while (n) {
            auto v = n % 16;
            if (v >= 2 && v <= 9)
                return "ERROR";
            h += H[v];
            n /= 16;
        }
        reverse(begin(h), end(h));
        return h;
    }
};