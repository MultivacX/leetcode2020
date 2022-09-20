// 2396. Strictly Palindromic Number
// https://leetcode.com/problems/strictly-palindromic-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Strictly Palindromic Number.
// Memory Usage: 6.1 MB, less than 16.73% of C++ online submissions for Strictly Palindromic Number.

class Solution
{
    bool isPalindromic(vector<int> &v)
    {
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            if (v[i] != v[j])
                return false;
            ++i, --j;
        }
        return true;
    }

public:
    bool isStrictlyPalindromic(int n)
    {
        if (n % 2 == 0)
            return false;

        for (int k = 2; k <= n - 2; ++k)
        {
            vector<int> v;
            int x = n;
            while (x)
            {
                int r = x % k;
                v.push_back(r);
                x /= k;
            }
            if (!isPalindromic(v))
                return false;
        }

        return true;
    }
};