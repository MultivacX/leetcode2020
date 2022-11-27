// 2481. Minimum Cuts to Divide a Circle
// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cuts to Divide a Circle.
// Memory Usage: 6 MB, less than 16.67% of C++ online submissions for Minimum Cuts to Divide a Circle.

class Solution
{
public:
    int numberOfCuts(int n)
    {
        if (n == 1)
            return 0;
        return n % 2 == 0 ? n / 2 : n;
    }
};