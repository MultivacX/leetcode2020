// 1663. Smallest String With A Given Numeric Value
// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

// Runtime: 56 ms, faster than 75.00% of C++ online submissions for Smallest String With A Given Numeric Value.
// Memory Usage: 21.5 MB, less than 41.67% of C++ online submissions for Smallest String With A Given Numeric Value.
    
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, ' ');
        for (int i = 0; i < n; ++i) {
            if (i + 1 == n) {
                s[i] = k + 'a' - 1;
            } else {
                int v = k - (n - i - 1) * 26;
                v = v <= 0 ? 1 : v;
                k -= v;
                s[i] = v + 'a' - 1;    
            }
        }
        return s;
    }
};