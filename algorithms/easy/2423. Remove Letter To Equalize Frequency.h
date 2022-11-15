// 2423. Remove Letter To Equalize Frequency
// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

// Runtime: 5 ms, faster than 34.72% of C++ online submissions for Remove Letter To Equalize Frequency.
// Memory Usage: 6.1 MB, less than 92.22% of C++ online submissions for Remove Letter To Equalize Frequency.

class Solution
{
public:
    bool equalFrequency(string word)
    {
        int f[26] = {0};
        for (char c : word)
            ++f[c - 'a'];

        sort(begin(f), end(f));

        if (f[25] == 1 || f[24] == 0)
            return true;

        int l = 0;
        while (f[l] == 0)
            ++l;

        return (f[l] == f[24] && f[24] + 1 == f[25]) || (f[l] == 1 && f[l + 1] == f[25]);
    }
};