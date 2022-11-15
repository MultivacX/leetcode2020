// 2437. Number of Valid Clock Times
// https://leetcode.com/problems/number-of-valid-clock-times/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Valid Clock Times.
// Memory Usage: 6 MB, less than 7.67% of C++ online submissions for Number of Valid Clock Times.

class Solution
{
public:
    int countTime(string time)
    {
        int sec = (time[3] == '?' ? 6 : 1) * (time[4] == '?' ? 10 : 1);
        int h = 1;
        if (time[0] == '?')
        {
            if (time[1] == '?')
            {
                h = 24;
            }
            else if (time[1] <= '3')
            {
                h = 3;
            }
            else
            {
                h = 2;
            }
        }
        else if (time[0] == '0' || time[0] == '1')
        {
            h = time[1] == '?' ? 10 : 1;
        }
        else if (time[0] == '2')
        {
            h = time[1] == '?' ? 4 : 1;
        }
        return sec * h;
    }
};