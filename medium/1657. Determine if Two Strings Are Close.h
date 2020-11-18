// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/

// Runtime: 92 ms, faster than 72.71% of C++ online submissions for Determine if Two Strings Are Close.
// Memory Usage: 20.9 MB, less than 74.53% of C++ online submissions for Determine if Two Strings Are Close.

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        
        vector<int> cnt1(26, 0);
        for (char c : word1) ++cnt1[c - 'a'];
        vector<int> cnt2(26, 0);
        for (char c : word2) ++cnt2[c - 'a'];
        
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] == 0 && cnt2[i] != 0) return false;
            if (cnt1[i] != 0 && cnt2[i] == 0) return false;
        }
        sort(begin(cnt1), end(cnt1));
        sort(begin(cnt2), end(cnt2));
        for (int i = 0; i < 26; ++i) 
            if (cnt1[i] != cnt2[i])  return false;
        return true;
    }
};