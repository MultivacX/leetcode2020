// 2222. Number of Ways to Select Buildings
// https://leetcode.com/problems/number-of-ways-to-select-buildings/

// Runtime: 381 ms, faster than 34.85% of C++ online submissions for Number of Ways to Select Buildings.
// Memory Usage: 40.1 MB, less than 42.04% of C++ online submissions for Number of Ways to Select Buildings.

class Solution
{
public:
    long long numberOfWays(string s)
    {
        vector<int> k;
        int n = s.length();
        int j = 1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i - 1] == s[i])
            {
                ++j;
            }
            else
            {
                k.push_back(j);
                j = 1;
            }
        }
        k.push_back(j);

        n = k.size();
        vector<int> v(n);
        for (int i = 0, e = 0, o = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                v[i] = o;
                e += k[i];
            }
            else
            {
                v[i] = e;
                o += k[i];
            }
        }

        long long res = 0;
        for (int i = n - 1, e = 0, o = 0; i >= 0; --i)
        {
            if (i % 2 == 0)
            {
                res += (long long)v[i] * k[i] * o;
                e += k[i];
            }
            else
            {
                res += (long long)v[i] * k[i] * e;
                o += k[i];
            }
        }
        return res;
    }
};