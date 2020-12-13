// 1062. Longest Repeating Substring
// https://leetcode.com/problems/longest-repeating-substring/

// Runtime: 1628 ms, faster than 11.60% of C++ online submissions for Longest Repeating Substring.
// Memory Usage: 623.1 MB, less than 10.80% of C++ online submissions for Longest Repeating Substring.
    
class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int ans = 0;
        const int n = S.length();
        for (int l = 1; l < n; ++l) {
            unordered_set<string> s;
            for (int i = 0; i + l <= n; ++i) {
                if (!s.insert(S.substr(i, l)).second) {
                    ans = l;
                    break;
                }
            }
        }
        return ans;
    }
};