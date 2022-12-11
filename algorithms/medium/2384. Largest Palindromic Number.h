// 2384. Largest Palindromic Number
// https://leetcode.com/problems/largest-palindromic-number/

class Solution
{
public:
    string largestPalindromic(string num)
    {
        int a[10] = {0};
        for (char c : num)
            ++a[c - '0'];

        string s;
        int j = -1;
        for (int i = 9; i > 0; --i)
        {
            while (a[i] > 1)
            {
                s.append(1, '0' + i);
                a[i] -= 2;
            }
            if (a[i] > 0 && j == -1)
                j = i;
        }

        string t;
        if (j != -1)
        {
            if (a[0] > 1 && s.length() > 0)
            {
                s.append(a[0] / 2, '0');
            }
            t = s;
            s.append(1, '0' + j);
        }
        else if (a[0])
        {
            t = s;
            s.append(a[0], '0');
        }
        else
        {
            t = s;
        }

        if (!t.empty())
        {
            reverse(t.begin(), t.end());
            s.append(t);
        }

        return s[0] == '0' ? "0" : s;
    }
};