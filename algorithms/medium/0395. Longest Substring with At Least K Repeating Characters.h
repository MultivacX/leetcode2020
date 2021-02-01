// 395. Longest Substring with At Least K Repeating Characters

// Runtime: 184 ms, faster than 12.84% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage: 61 MB, less than 18.18% of C++ online submissions for Longest Substring with At Least K Repeating Characters.

class Solution {
public:
    int longestSubstring(string s, int k) {
        const int n = s.length();
        if (n == 0)
            return 0;
        if (k == 0)
            return n;
        
        vector<int> cnt(26, 0);
        for (char c : s)
            ++cnt[c - 'a'];
        // int m = 0;
        // for (int i = 0; i < 26; ++i) {
        //     if (cnt[i] >= k)
        //         continue;
        //     m |= 1 << i;
        // }
        // if (m == 0)
        //     return s.length();
        int idx = 0;
        while (idx < n && cnt[s[idx] - 'a'] >= k) ++idx;
        if (idx == n) return n;
        
        return max(longestSubstring(s.substr(0, idx), k), longestSubstring(s.substr(idx + 1), k)); 
    }
};