// 2405. Optimal Partition of String
// https://leetcode.com/problems/optimal-partition-of-string/

// Runtime: 33 ms, faster than 96.34% of C++ online submissions for Optimal Partition of String.
// Memory Usage: 10.2 MB, less than 97.30% of C++ online submissions for Optimal Partition of String.

class Solution
{
public:
    int partitionString(string s)
    {
        const int n = s.length();
        int res = 1, m = 1 << (s[0] - 'a');
        for (int i = 1; i < n; ++i)
        {
            int b = 1 << (s[i] - 'a');
            if (m & b)
                m = 0, ++res;
            m |= b;
        }
        return res;
    }
};