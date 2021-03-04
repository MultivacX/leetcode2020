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


class Solution {
public:
    bool isAnagram(string s, string t) {
        const int n = s.length();
        if (n != t.length()) return false;
        if (n == 0) return true;
        
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) 
            ++cnt[s[i] - 'a'],
            --cnt[t[i] - 'a'];

        for (int i : cnt)
            if (i != 0)
                return false;
        return true;
    }
};