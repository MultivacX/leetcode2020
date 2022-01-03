// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string/

// Runtime: 320 ms, faster than 9.19% of C++ online submissions for Adding Spaces to a String.
// Memory Usage: 81.3 MB, less than 64.26% of C++ online submissions for Adding Spaces to a String.

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string t;
        for (int i = 0, j = 0; i < s.length(); ++i)
        {
            if (j < spaces.size() && i == spaces[j])
            {
                t += " ";
                ++j;
            }
            t += s[i];
        }
        return t;
    }
};