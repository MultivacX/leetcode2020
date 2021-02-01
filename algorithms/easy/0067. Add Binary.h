// 67. Add Binary
// https://leetcode.com/problems/add-binary/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
// Memory Usage: 6.8 MB, less than 66.53% of C++ online submissions for Add Binary.

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        string c;
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < a.length() || j < b.length()) {
            if (i < a.length()) k += a[i++] - '0';
            if (j < b.length()) k += b[j++] - '0';
            c += k % 2 == 0 ? '0' : '1';
            k /= 2;
        }
        if (k) c += '1';
        reverse(begin(c), end(c));
        return c;
    }
};