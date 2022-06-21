// 2259. Remove Digit From Number to Maximize Result
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Digit From Number to Maximize Result.
// Memory Usage: 6.2 MB, less than 60.99% of C++ online submissions for Remove Digit From Number to Maximize Result.

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        const int n = number.length();
        int k = count(number.begin(), number.end(), digit);
        string s(n - 1, '0');
        for (int i = 0, j = 0; i < n; ++i)
        {
            if (k == 0 || number[i] != digit)
            {
                s[j++] = number[i];
            }
            else if (k == 1 || i + 1 == n || number[i] < number[i + 1])
            {
                k = 0;
            }
            else
            {
                s[j++] = number[i];
                --k;
            }
        }
        return s;
    }
};