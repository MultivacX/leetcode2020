// 2317. Maximum XOR After Operations
// https://leetcode.com/problems/maximum-xor-after-operations/

// Runtime: 209 ms, faster than 26.66% of C++ online submissions for Maximum XOR After Operations .
// Memory Usage: 48 MB, less than 87.39% of C++ online submissions for Maximum XOR After Operations .

class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int res = 0;
        for (int i : nums)
            res |= i;
        return res;
    }
};