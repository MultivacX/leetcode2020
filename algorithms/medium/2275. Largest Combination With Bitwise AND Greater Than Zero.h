// 2275. Largest Combination With Bitwise AND Greater Than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

// Runtime: 153 ms, faster than 94.22% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.
// Memory Usage: 57.5 MB, less than 47.65% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        // 1 ~ 1000 0000 : 0 ~ 23
        int res = 0;
        for (int i = 0; i < 24; ++i)
        {
            int k = 0;
            for (int v : candidates)
                if (v & (1 << i))
                    ++k;
            res = max(res, k);
        }
        return res;
    }
};