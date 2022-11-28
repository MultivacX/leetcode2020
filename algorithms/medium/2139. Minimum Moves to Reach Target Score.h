// 2139. Minimum Moves to Reach Target Score
// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Moves to Reach Target Score.
// Memory Usage: 5.7 MB, less than 94.94% of C++ online submissions for Minimum Moves to Reach Target Score.

class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int res = 0;
        while (target > 1 && maxDoubles > 0)
        {
            if (target & 1)
            {
                target -= 1;
                res += 1;
            }
            target >>= 1;
            maxDoubles -= 1;
            res += 1;
        }
        return res + target - 1;
    }
};