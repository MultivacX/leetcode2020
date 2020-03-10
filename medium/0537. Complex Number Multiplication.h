// 537. Complex Number Multiplication

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complex Number Multiplication.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Complex Number Multiplication.

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto ac = ab(a);
        auto bc = ab(b);
        // cout << ac.first << ", " << ac.second << endl;
        // cout << bc.first << ", " << bc.second << endl;
        int _a = ac.first * bc.first - ac.second * bc.second;
        int _b = ac.first * bc.second + ac.second * bc.first;
        return to_string(_a) + "+" + to_string(_b) + "i";
    }
    
    pair<int, int> ab(const string& c) {
        bool negative = c[0] == '-';
        int idx = c[0] == '-' ? 1 : 0;
        
        int a = 0;
        while (c[idx] >= '0' && c[idx] <= '9') {
            a = a * 10 + (c[idx] - '0');
            ++idx;
        }
        if (negative) a *= -1;
        
        ++idx; // skip '+'
        
        negative = c[idx] == '-';
        idx += c[idx] == '-' ? 1 : 0;
        int b = 0;
        while (c[idx] >= '0' && c[idx] <= '9') {
            b = b * 10 + (c[idx] - '0');
            ++idx;
        }
        if (negative) b *= -1;
        
        return {a, b};
    }
};