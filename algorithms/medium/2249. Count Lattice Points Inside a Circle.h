// 2249. Count Lattice Points Inside a Circle
// https://leetcode.com/problems/count-lattice-points-inside-a-circle/

// Runtime: 377 ms, faster than 86.94% of C++ online submissions for Count Lattice Points Inside a Circle.
// Memory Usage: 7.9 MB, less than 94.03% of C++ online submissions for Count Lattice Points Inside a Circle.

class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        int minx = INT_MAX, maxx = INT_MIN;
        int miny = INT_MAX, maxy = INT_MIN;
        for (const auto &c : circles)
        {
            minx = min(minx, c[0] - c[2]);
            maxx = max(maxx, c[0] + c[2]);
            miny = min(miny, c[1] - c[2]);
            maxy = max(maxy, c[1] + c[2]);
        }

        int k = 0;
        for (int x = minx; x <= maxx; ++x)
            for (int y = miny; y <= maxy; ++y)
                for (const auto &c : circles)
                    if ((x - c[0]) * (x - c[0]) + (y - c[1]) * (y - c[1]) <= c[2] * c[2])
                    {
                        ++k;
                        break;
                    }
        return k;
    }
};