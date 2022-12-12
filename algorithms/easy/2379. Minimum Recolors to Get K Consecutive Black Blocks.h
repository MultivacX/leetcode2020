// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int res = k;
        for (int i = 0, l = 0, r = 0; i < blocks.length(); ++i)
        {
            if (blocks[i] == 'W')
                ++r;
            if (i >= k && blocks[i - k] == 'W')
                ++l;
            if (i + 1 >= k)
                res = min(res, r - l);
        }
        return res;
    }
};