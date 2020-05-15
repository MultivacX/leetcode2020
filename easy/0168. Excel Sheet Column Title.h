// 168. Excel Sheet Column Title

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Excel Sheet Column Title.

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
            int a = n % 26;
            if (a == 0) a = 26;
            // cout << (char)(a - 1 + 'A') << endl;
            n -= a;
            n /= 26;
            s += a - 1 + 'A';
        }
        reverse(begin(s), end(s));
        return s;
    }
};