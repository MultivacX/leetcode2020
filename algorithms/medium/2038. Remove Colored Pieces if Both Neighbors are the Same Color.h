// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

// Runtime: 67 ms, faster than 44.58% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.
// Memory Usage: 13.3 MB, less than 77.86% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        const int n = colors.size();
        int a = 0, b = 0, l = 0;
        for (int i = 1; i < n; ++i)
        {
            if (colors[l] != colors[i])
            {
                int k = i - l - 2;
                if (k > 0)
                    colors[l] == 'A' ? a += k : b += k;
                l = i;
            }
            else if (i + 1 == n)
            {
                int k = i - l - 1;
                if (k > 0)
                    colors[l] == 'A' ? a += k : b += k;
                l = i;
            }
        }
        // cout << a << ", " << b << endl;
        return a > b;
    }
};