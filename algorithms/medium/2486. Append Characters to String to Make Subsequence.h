// 2486. Append Characters to String to Make Subsequence
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// Runtime: 69 ms, faster than 35.35% of C++ online submissions for Append Characters to String to Make Subsequence.
// Memory Usage: 10.8 MB, less than 42.82% of C++ online submissions for Append Characters to String to Make Subsequence.

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        const int m = s.length(), n = t.length();
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (s[i] == t[j])
                ++j;
            ++i;
        }
        return n - j;
    }
};