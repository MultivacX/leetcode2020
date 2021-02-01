// 392. Is Subsequence

// Runtime: 64 ms, faster than 64.31% of C++ online submissions for Is Subsequence.
// Memory Usage: 17.2 MB, less than 14.29% of C++ online submissions for Is Subsequence.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int sl = s.length();
        const int tl = t.length();
        if (sl > tl) return false;
        if (sl == tl) return s == t;
        
        int si = 0;
        int ti = 0;
        while (si < sl && ti < tl) 
            if (s[si] == t[ti++]) ++si;
        return si == sl;
    }
};