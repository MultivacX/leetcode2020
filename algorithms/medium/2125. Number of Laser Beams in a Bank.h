// 2125. Number of Laser Beams in a Bank
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// Runtime: 126 ms, faster than 72.96% of C++ online submissions for Number of Laser Beams in a Bank.
// Memory Usage: 23 MB, less than 76.42% of C++ online submissions for Number of Laser Beams in a Bank.

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int res = 0, k = 0;
        for (const string &r : bank)
        {
            int i = 0;
            for (char c : r)
                i += c - '0';
            res += i * k;
            if (i)
                k = i;
        }
        return res;
    }
};