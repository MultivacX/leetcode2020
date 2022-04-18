// 2006. Count Number of Pairs With Absolute Difference K
// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

// Runtime: 7 ms, faster than 97.47% of C++ online submissions for Count Number of Pairs With Absolute Difference K.
// Memory Usage: 12.6 MB, less than 30.31% of C++ online submissions for Count Number of Pairs With Absolute Difference K.

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        vector<int> cnts(101);
        for (int i : nums)
            ++cnts[i];

        int pairs = 0;
        for (int i = 1; i + k <= 100; ++i)
        {
            pairs += cnts[i] * cnts[i + k];
        }
        return pairs;
    }
};