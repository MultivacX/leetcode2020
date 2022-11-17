// 2269. Find the K-Beauty of a Number
// https://leetcode.com/problems/find-the-k-beauty-of-a-number/

// Runtime: 3 ms, faster than 43.04% of C++ online submissions for Find the K-Beauty of a Number.
// Memory Usage: 6 MB, less than 17.94% of C++ online submissions for Find the K-Beauty of a Number.

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string s(to_string(num));
        int res = 0;
        for (int i = 0; i + k <= s.length(); ++i)
        {
            int x = stoi(s.substr(i, k));
            res += x > 0 && num % x == 0;
        }
        return res;
    }
};