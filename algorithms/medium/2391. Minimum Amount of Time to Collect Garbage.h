// 2391. Minimum Amount of Time to Collect Garbage
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

// Runtime: 641 ms, faster than 11.88% of C++ online submissions for Minimum Amount of Time to Collect Garbage.
// Memory Usage: 102.1 MB, less than 94.92% of C++ online submissions for Minimum Amount of Time to Collect Garbage.

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int res = 0, m = -1, p = -1, g = -1, n = garbage.size();
        for (int i = 0; i < n; ++i)
        {
            res += garbage[i].length();
            if (m == -1 || p == -1 || g == -1)
            {
                int j = n - 1 - i;
                for (char c : garbage[j])
                {
                    if (m == -1 && c == 'M')
                        m = j;
                    else if (p == -1 && c == 'P')
                        p = j;
                    else if (g == -1 && c == 'G')
                        g = j;
                }
            }
        }
        // cout << m << ' ' << p << ' ' << ' ' << g << endl;
        for (int i = 0; i < travel.size(); ++i)
        {
            if (i < m)
                res += travel[i];
            if (i < p)
                res += travel[i];
            if (i < g)
                res += travel[i];
        }
        return res;
    }
};

// Runtime: 533 ms, faster than 19.18% of C++ online submissions for Minimum Amount of Time to Collect Garbage.
// Memory Usage: 102.2 MB, less than 75.62% of C++ online submissions for Minimum Amount of Time to Collect Garbage.

class Solution
{
    pair<int, int> getInterval(vector<string> &garbage, char c)
    {
        int l = -1, r = -1;
        int i = 0, j = garbage.size() - 1;

        while (i < garbage.size() && l < 0)
        {
            for (char k : garbage[i])
            {
                if (k == c)
                {
                    l = i;
                    break;
                }
            }
            ++i;
        }

        while (j >= 0 && r < 0)
        {
            for (char k : garbage[j])
            {
                if (k == c)
                {
                    r = j;
                    break;
                }
            }
            --j;
        }
        return {l, r};
    }

    int getMinutes(vector<string> &garbage, vector<int> &travel, char c)
    {
        int res = 0;
        auto m = getInterval(garbage, c);
        // cout << m.first << ", " << m.second;
        for (int i = 0; i <= m.second; ++i)
        {
            if (i > 0)
                res += travel[i - 1];
            if (i < m.first)
                continue;
            for (char k : garbage[i])
            {
                if (k == c)
                {
                    ++res;
                }
            }
        }
        // cout << "  " << res << endl;
        return res;
    }

public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        return getMinutes(garbage, travel, 'M') + getMinutes(garbage, travel, 'P') + getMinutes(garbage, travel, 'G');
    }
};