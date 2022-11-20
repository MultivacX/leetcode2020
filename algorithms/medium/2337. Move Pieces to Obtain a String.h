// 2337. Move Pieces to Obtain a String
// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

// Runtime: 133 ms, faster than 61.03% of C++ online submissions for Move Pieces to Obtain a String.
// Memory Usage: 19.1 MB, less than 64.03% of C++ online submissions for Move Pieces to Obtain a String.

class Solution
{
public:
    bool canChange(string start, string target)
    {
        const int n = start.length();

        int L = 0, R = 0;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (target[i] == 'L')
                ++L;
            else if (target[i] == 'R')
                ++R;
            if (start[i] == 'L')
                --L;
            else if (start[i] == 'R')
                --R;
            ++i;
        }
        if (L != 0 || R != 0)
            return false;

        i = 0, j = 0;
        while (i < n && j < n)
        {
            while (i < n && target[i] == '_')
                ++i;
            if (i == n)
                break;
            while (j < n && start[j] == '_')
                ++j;
            if (j == n)
                break;

            // cout << i << ':' << target[i] << "  " << j << ':' << start[j] << endl;

            if (target[i] != start[j])
                return false;

            if (target[i] == 'L')
            {
                if (i > j)
                    return false;
                ++i, ++j;
            }
            else
            {
                if (i < j)
                    return false;
                ++i, ++j;
            }
        }

        return true;
    }
};