// 5. Longest Palindromic Substring

// Runtime: 36 ms, faster than 84.10% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.

// Time Complexity: O(N * N).
// Space Complexity: O(1).

class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.length();
        int L = 0;
        int R = 0;
        for (int i = 0; i < s.length(); ++i) {
            int l = i;
            int r = i;
            while (l >= 0 && r < N && s[l] == s[r]) --l, ++r;
            if (r - l - 2 > R - L) L = l + 1, R = r - 1;
            
            l = i;
            r = i;
            while (l >= 0 && r + 1 < N && s[l] == s[r + 1]) --l, ++r;
            if (r > l && r + 1 - l - 2 > R - L) L = l + 1, R = r;
        }
        // cout << L << ", " << R << endl;
        return s.substr(L, R - L + 1);
    }
};