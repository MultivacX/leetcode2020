// 2023. Number of Pairs of Strings With Concatenation Equal to Target
// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

// Runtime: 12 ms, faster than 92.09% of C++ online submissions for Number of Pairs of Strings With Concatenation Equal to Target.
// Memory Usage: 10.6 MB, less than 91.87% of C++ online submissions for Number of Pairs of Strings With Concatenation Equal to Target.

class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        unordered_map<string, int> m;
        for (auto i : nums)
            ++m[i];

        int res = 0;
        string s, t;
        for (int i = 0; i + 1 < target.length(); ++i)
        {
            s += target[i];
            auto a = m.find(s);
            if (a == m.end())
                continue;

            t = target.substr(i + 1);
            auto b = m.find(t);
            if (b == m.end())
                continue;

            if (s == t)
                res += a->second * (b->second - 1);
            else
                res += a->second * b->second;
        }
        return res;
    }
};