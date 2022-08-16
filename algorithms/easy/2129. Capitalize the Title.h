// 2129. Capitalize the Title
// https://leetcode.com/problems/capitalize-the-title/

// Runtime: 5 ms, faster than 36.37% of C++ online submissions for Capitalize the Title.
// Memory Usage: 6.1 MB, less than 91.33% of C++ online submissions for Capitalize the Title.

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        const int n = title.length();
        for (int i = 0; i < n; ++i)
        {
            if (title[i] == ' ')
                continue;

            if ((i - 1 < 0 || title[i - 1] == ' ') && (i + 1 >= n || title[i + 1] == ' '))
                title[i] = tolower(title[i]);

            else if ((i - 1 < 0 || title[i - 1] == ' ') && (i + 2 >= n || title[i + 2] == ' '))
                title[i] = tolower(title[i]);

            else if ((i - 2 < 0 || title[i - 2] == ' ') && (i + 1 >= n || title[i + 1] == ' '))
                title[i] = tolower(title[i]);

            else if (i - 1 < 0 || title[i - 1] == ' ')
                title[i] = toupper(title[i]);

            else
                title[i] = tolower(title[i]);
        }
        return title;
    }
};