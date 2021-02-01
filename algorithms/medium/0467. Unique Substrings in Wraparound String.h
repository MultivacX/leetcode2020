// 467. Unique Substrings in Wraparound String

// Runtime: 32 ms, faster than 9.55% of C++ online submissions for Unique Substrings in Wraparound String.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Unique Substrings in Wraparound String.

// Time Complexity: O(26 * N).
// Space Complexity: O(1).

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        for (int i = 0; i < 26; ++i) ans += count(p, i);
        return ans;
    }
    
    int count(const string& p, const int n) {
        int ans = 0;
        const int N = p.length();
        int i = 0;
        while (i < N) {
            if (p[i] - 'a' != n) {
                ++i;
                continue;
            }
            
            int len = 0;
            int num = n;
            while (i < N && p[i] - 'a' == num) {
                ++len;
                num = (num + 1) % 26;
                ++i;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};