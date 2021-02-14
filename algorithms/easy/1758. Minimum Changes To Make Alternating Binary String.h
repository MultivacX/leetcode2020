// 1758. Minimum Changes To Make Alternating Binary String
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Minimum Changes To Make Alternating Binary String.
// Memory Usage: 7 MB, less than 50.00% of C++ online submissions for Minimum Changes To Make Alternating Binary String.
    
class Solution {
public:
    int minOperations(string s) {
        const int n = s.length();
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                s[i] == '0' ? ++a : ++b;
            } else {
                s[i] == '1' ? ++a : ++b;
            }
        }
        return min(a, b);
    }
};