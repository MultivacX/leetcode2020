// 2299. Strong Password Checker II
// https://leetcode.com/problems/strong-password-checker-ii/

// Runtime: 2 ms, faster than 53.89% of C++ online submissions for Strong Password Checker II.
// Memory Usage: 6.1 MB, less than 51.64% of C++ online submissions for Strong Password Checker II.

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        const int n = password.length();
        if (n < 8)
            return false;

        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool special = false;
        for (int i = 0; i < n; ++i)
        {
            char c = password[i];
            if ('a' <= c && c <= 'z')
                lowercase = true;
            else if ('A' <= c && c <= 'Z')
                uppercase = true;
            else if ('0' <= c && c <= '9')
                digit = true;
            else
            {
                special = true;
            }

            if (i > 0 && password[i - 1] == c)
                return false;
        }
        return lowercase && uppercase && digit && special;
    }
};