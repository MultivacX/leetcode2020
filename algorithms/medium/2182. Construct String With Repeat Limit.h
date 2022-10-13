// 2182. Construct String With Repeat Limit
// https://leetcode.com/problems/construct-string-with-repeat-limit/

// Runtime: 242 ms, faster than 48.28% of C++ online submissions for Construct String With Repeat Limit.
// Memory Usage: 24.5 MB, less than 86.95% of C++ online submissions for Construct String With Repeat Limit.

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int m[26] = {0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0};

        for (char c : s)
            ++m[c - 'a'];

        string t;
        int i = 25;
        while (i >= 0)
        {
            if (m[i] == 0)
            {
                --i;
                continue;
            }

            int k = 0;
            while (m[i] && k < repeatLimit)
            {
                t += 'a' + i;
                --m[i];
                ++k;
            }

            if (k == repeatLimit && m[i])
            {
                int j = i - 1;
                while (j >= 0)
                {
                    if (m[j] != 0)
                    {
                        t += 'a' + j;
                        --m[j];
                        break;
                    }
                    --j;
                }
                if (j < 0)
                    break;
            }
        }
        return t;
    }
};