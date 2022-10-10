// 2165. Smallest Value of the Rearranged Number
// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Value of the Rearranged Number.
// Memory Usage: 5.8 MB, less than 98.53% of C++ online submissions for Smallest Value of the Rearranged Number.

class Solution
{
public:
    long long smallestNumber(long long num)
    {
        int k[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        bool positive = num >= 0;
        if (num < 0)
            num = -num;
        while (num)
        {
            ++k[num % 10];
            num /= 10;
        }

        long long res = 0;
        if (positive)
        {
            for (int i = 1; i < 10; ++i)
            {
                if (k[i] > 0 && k[0] > 0)
                {
                    k[i]--;
                    res = res * 10 + i;
                    while (k[0]--)
                        res *= 10;
                    while (k[i]--)
                        res = res * 10 + i;
                }
                else
                    while (k[i]--)
                        res = res * 10 + i;
            }
        }
        else
        {
            for (int i = 9; i > 0; --i)
                while (k[i]--)
                    res = res * 10 + i;
            while (k[0]--)
                res *= 10;
            res = -res;
        }
        return res;
    }
};