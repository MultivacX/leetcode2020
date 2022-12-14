// 2287. Rearrange Characters to Make Target String

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        int a[26] = {0};
        for (char c : s)
            ++a[c - 'a'];

        int b[26] = {0};
        for (char c : target)
            ++b[c - 'a'];

        int res = INT_MAX;
        for (int i = 0; i < 26; ++i)
        {
            if (b[i] == 0)
                continue;
            if (a[i] < b[i])
                return 0;
            res = min(res, a[i] / b[i]);
        }
        return res;
    }
};