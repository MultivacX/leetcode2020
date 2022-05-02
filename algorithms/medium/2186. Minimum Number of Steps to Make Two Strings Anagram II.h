// 2186. Minimum Number of Steps to Make Two Strings Anagram II
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

// Runtime: 155 ms, faster than 58.52% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.
// Memory Usage: 28.9 MB, less than 91.01% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram II.

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int sa[128];
        int ta[128];
        for (int i = 0; i < 128; ++i)
            sa[i] = ta[i] = 0;
        for (char c : s)
            ++sa[c];
        for (char c : t)
            ++ta[c];

        int res = 0;
        for (int i = 0; i < 128; ++i)
            res += abs(sa[i] - ta[i]);
        return res;
    }
};