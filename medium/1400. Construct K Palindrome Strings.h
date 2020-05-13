// 1400. Construct K Palindrome Strings

// Runtime: 88 ms, faster than 33.69% of C++ online submissions for Construct K Palindrome Strings.
// Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Construct K Palindrome Strings.

// Time Complexity: O(s.length()).
// Space Complexity: O(1).

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() <= k) return s.length() == k;
        
        vector<int> cnt(26, 0);
        for (const char& c : s) ++cnt[c - 'a'];
        int odd = 0;
        // int even = 0;
        for (int i : cnt) {
            if (i == 0) continue;
            if (i & 1) ++odd;
            // else ++even;
        }
        return odd <= k;
    }
};