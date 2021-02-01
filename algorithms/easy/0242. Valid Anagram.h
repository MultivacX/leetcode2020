// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

// Runtime: 16 ms, faster than 66.08% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.6 MB, less than 33.93% of C++ online submissions for Valid Anagram.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> cnt(26, 0);
        for (char c : s) ++cnt[c - 'a'];
        for (char c : t) --cnt[c - 'a'];
        for (int i : cnt) if (i) return false;
        return true;
    }
};