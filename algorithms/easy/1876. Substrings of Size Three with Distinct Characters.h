// 1876. Substrings of Size Three with Distinct Characters
// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// Memory Usage: 6.2 MB, less than 50.00% of C++ online submissions for Substrings of Size Three with Distinct Characters.
    
class Solution {
public:
    int countGoodSubstrings(string s) {
        const int n = s.length();
        int ans = 0;
        for (int i = 0; i + 2 < n; ++i)
            if (s[i]     != s[i + 1] &&
                s[i + 1] != s[i + 2] &&
                s[i + 2] != s[i])
                ++ans;
        return ans;
    }
};