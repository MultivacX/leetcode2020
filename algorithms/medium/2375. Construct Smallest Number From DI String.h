// 2375. Construct Smallest Number From DI String
// https://leetcode.com/problems/construct-smallest-number-from-di-string/

// Runtime: 3 ms, faster than 57.22% of C++ online submissions for Construct Smallest Number From DI String.
// Memory Usage: 6 MB, less than 68.31% of C++ online submissions for Construct Smallest Number From DI String.

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        stack<char> s;
        int i = 1;
        string res;
        for (char c : pattern)
        {
            s.push('0' + i);
            ++i;
            while (c == 'I' && !s.empty())
            {
                res += s.top();
                s.pop();
            }
        }
        s.push('0' + i);
        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }
        return res;
    }
};