// 389. Find the Difference

// Runtime: 4 ms, faster than 85.48% of C++ online submissions for Find the Difference.
// Memory Usage: 9.1 MB, less than 55.56% of C++ online submissions for Find the Difference.

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (char c : s) 
            ++cnt[c - 'a'];
        for (char c : t) {
            --cnt[c - 'a'];
            if (cnt[c - 'a'] < 0)
                return c;
        }
        return '\0';
    }
};