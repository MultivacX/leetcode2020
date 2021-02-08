// 1750. Minimum Length of String After Deleting Similar Ends
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// Runtime: 32 ms, faster than 10.00% of C++ online submissions for Minimum Length of String After Deleting Similar Ends.
// Memory Usage: 12.6 MB, less than 10.00% of C++ online submissions for Minimum Length of String After Deleting Similar Ends.
    
class Solution {
public:
    int minimumLength(string s) {
        const int n = s.length();
        if (n == 1) return 1;
        int i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) {
            char c = s[i];
            while (i < n && c == s[i]) ++i;
            if (i >= j) return 0;
            while (j >= 0 && c == s[j]) --j;
            // for (int k = i; k <= j; ++k) cout << s[k]; cout << endl;
        }
        return j - i + 1;
    }
};