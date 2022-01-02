// 2124. Check if All A's Appears Before All B's
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/submissions/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if All A's Appears Before All B's.
// Memory Usage: 6.2 MB, less than 64.71% of C++ online submissions for Check if All A's Appears Before All B's.

class Solution
{
public:
    bool checkString(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != 'b')
            {
                ++i;
                continue;
            }
            if (s[j] != 'a')
            {
                --j;
                continue;
            }
            if (i < j && s[i] == 'b' && s[j] == 'a')
            {
                break;
            }
        }
        return i >= j;
    }
};