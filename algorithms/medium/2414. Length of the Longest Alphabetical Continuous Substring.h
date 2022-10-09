// 2414. Length of the Longest Alphabetical Continuous Substring
// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

// Runtime: 160 ms, faster than 11.93% of C++ online submissions for Length of the Longest Alphabetical Continuous Substring.
// Memory Usage: 15.4 MB, less than 10.20% of C++ online submissions for Length of the Longest Alphabetical Continuous Substring.

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        const int n = s.length();
        int i = s[0], j = s[0], res = 1;
        for (int k = 1; k < n; ++k)
        {
            if (s[k] == j + 1)
            {
                j = s[k];
            }
            else
            {
                i = j = s[k];
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};