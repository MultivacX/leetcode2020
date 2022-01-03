// 2108. Find First Palindromic String in the Array
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Runtime: 91 ms, faster than 10.71% of C++ online submissions for Find First Palindromic String in the Array.
// Memory Usage: 19.5 MB, less than 98.41% of C++ online submissions for Find First Palindromic String in the Array.

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (const auto &w : words)
        {
            int i = 0, j = w.length() - 1;
            while (i < j && w[i] == w[j])
            {
                ++i;
                --j;
            }
            if (i >= j)
            {
                return w;
            }
        }
        return "";
    }
};