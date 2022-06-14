// 2047. Number of Valid Words in a Sentence
// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/

// Runtime: 4 ms, faster than 85.60% of C++ online submissions for Number of Valid Words in a Sentence.
// Memory Usage: 6.8 MB, less than 96.53% of C++ online submissions for Number of Valid Words in a Sentence.

class Solution
{
    bool isLowercase(char c)
    {
        return 'a' <= c && c <= 'z';
    }

    bool isPunctuation(char c)
    {
        return c == '!' || c == '.' || c == ',';
    }

public:
    int countValidWords(string sentence)
    {
        const int n = sentence.length();
        int res = 0;
        int l = 0, h = 0, p = 0;
        for (int i = 0; i < n; ++i)
        {
            if (sentence[i] == ' ')
                continue;

            if (isLowercase(sentence[i]))
            {
                ++l;
            }
            else if (sentence[i] == '-')
            {
                ++h;
                if (h > 1)
                {
                    l = -10000;
                }
                else if (i == 0 || !isLowercase(sentence[i - 1]))
                {
                    l = -10000;
                }
                else if (i + 1 == n || !isLowercase(sentence[i + 1]))
                {
                    l = -10000;
                }
            }
            else if (isPunctuation(sentence[i]))
            {
                ++p;
                if (p > 1)
                {
                    l = -10000;
                }
                else if (i + 1 < n && sentence[i + 1] != ' ')
                {
                    l = -10000;
                }
                else
                {
                    ++l;
                }
            }
            else
            {
                l = -10000;
            }

            if (i + 1 == n || sentence[i + 1] == ' ')
            {
                if (l > 0)
                    ++res;

                l = 0, h = 0, p = 0;
            }
        }
        return res;
    }
};