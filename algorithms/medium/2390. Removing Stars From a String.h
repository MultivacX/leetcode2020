// 2390. Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string/

// Runtime: 96 ms, faster than 85.24% of C++ online submissions for Removing Stars From a String.
// Memory Usage: 25.7 MB, less than 73.04% of C++ online submissions for Removing Stars From a String.

class Solution
{
public:
    string removeStars(string s)
    {
        string t;
        for (char c : s)
        {
            if (c != '*')
            {
                t.push_back(c);
            }
            else if (!t.empty())
            {
                t.pop_back();
            }
        }
        return t;
    }
};