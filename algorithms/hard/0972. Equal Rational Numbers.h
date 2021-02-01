// 972. Equal Rational Numbers
// https://leetcode.com/problems/equal-rational-numbers/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Equal Rational Numbers.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Equal Rational Numbers.

class Solution {
    pair<uint64_t, uint64_t> get_rational(const string& s) {
        const int N = s.length();
        int i = 0;
        
        uint64_t integer_part = 0;
        while (i < N && s[i] != '.')
            integer_part = integer_part * 10 + s[i++] - '0';
        ++i; // skip '.'
        
        uint64_t non_repeating_part = 0;
        int non_repeating_part_len = 0;
        while (i < N && s[i] != '(') {
            non_repeating_part = non_repeating_part * 10 + s[i++] - '0';
            ++non_repeating_part_len;
        }
        ++i; // skip '('
        
        uint64_t repeating_part = 0;
        int repeating_part_len = 0;
        while (i < N && s[i] != ')') {
            repeating_part = repeating_part * 10 + s[i++] - '0';
            ++repeating_part_len;
        }
        
        if (non_repeating_part == 0 && repeating_part == 0) return {integer_part, 1};
        
        uint64_t x = repeating_part == 0 ? 1 : pow(10, repeating_part_len) - 1;
        // (nrp + rp / x) / pow(10, nrpl)
        uint64_t decimal_p = non_repeating_part * x + repeating_part;
        uint64_t decimal_q = x * pow(10, non_repeating_part_len);
        uint64_t decimal_gcd = gcd(decimal_p, decimal_q);
        if (decimal_gcd != 0) {
            decimal_p /= decimal_gcd;
            decimal_q /= decimal_gcd;   
        }
        
        uint64_t p = integer_part * decimal_q + decimal_p;
        uint64_t q = decimal_q;
        uint64_t gcd_ = gcd(p, q);
        if (gcd_) {
            p /= gcd_;
            q /= gcd_;
        }
        // cout << p << ", " << q << endl;
        return {p, q};
    }
    
public:
    bool isRationalEqual(string S, string T) {
        return get_rational(S) == get_rational(T);
    }
};