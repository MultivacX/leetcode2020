// 2177. Find Three Consecutive Integers That Sum to a Given Number
// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

// Runtime: 4 ms, faster than 21.07% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.
// Memory Usage: 6 MB, less than 94.15% of C++ online submissions for Find Three Consecutive Integers That Sum to a Given Number.

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        long long v = num / 3;
        if (v * 3 != num)
            return {};
        return {v - 1, v, v + 1};
    }
};