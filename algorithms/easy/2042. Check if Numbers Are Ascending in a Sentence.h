// 2042. Check if Numbers Are Ascending in a Sentence
// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

// Runtime: 5 ms, faster than 18.64% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.
// Memory Usage: 6.4 MB, less than 38.74% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        const int n = s.length();
        int i = 0, pre = 0;
        while (i < n)
        {
            int cur = -1;
            while (i < n)
            {
                if (isdigit(s[i]))
                {
                    if (cur < 0)
                    {
                        cur = s[i] - '0';
                    }
                    else
                    {
                        cur = cur * 10 + s[i] - '0';
                    }
                    ++i;
                }
                else
                {
                    ++i;
                    break;
                }
            }

            if (cur <= 0)
                continue;
            if (pre >= cur)
                return false;
            pre = cur;
        }
        return true;
    }
};