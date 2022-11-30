// 2400. Number of Ways to Reach a Position After Exactly k Steps
// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

// Runtime: 69 ms, faster than 77.71% of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.
// Memory Usage: 19.1 MB, less than 72.08% of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.

class Solution
{
    int m[3001][1001];

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        int d = abs(endPos - startPos);

        if (k < d)
            return 0;
        if (k == d)
            return 1;
        if ((k - d) & 1)
            return 0;

        int &res = m[startPos + 1000][k];
        if (res <= 0)
        {
            int64_t a = numberOfWays(startPos - 1, endPos, k - 1);
            int64_t b = numberOfWays(startPos + 1, endPos, k - 1);
            res = (a + b) % 1000000007;
        }
        return res;
    }
};