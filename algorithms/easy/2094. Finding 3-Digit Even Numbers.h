// 2094. Finding 3-Digit Even Numbers
// https://leetcode.com/problems/finding-3-digit-even-numbers/

// Runtime: 3 ms, faster than 98.54% of C++ online submissions for Finding 3-Digit Even Numbers.
// Memory Usage: 9.2 MB, less than 75.15% of C++ online submissions for Finding 3-Digit Even Numbers.

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int d : digits)
            ++a[d];

        vector<int> res;
        for (int i = 1; i <= 9; ++i)
        {
            if (a[i] == 0)
                continue;

            int vi = i * 100;
            --a[i];

            for (int j = 0; j <= 9; ++j)
            {
                if (a[j] == 0)
                    continue;

                int vj = vi + j * 10;
                --a[j];

                for (int k = 0; k <= 8; k += 2)
                {
                    if (a[k] == 0)
                        continue;

                    res.push_back(vj + k);
                }

                ++a[j];
            }

            ++a[i];
        }
        return res;
    }
};