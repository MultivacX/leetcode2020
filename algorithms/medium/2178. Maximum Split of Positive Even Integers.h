// 2178. Maximum Split of Positive Even Integers
// https://leetcode.com/problems/maximum-split-of-positive-even-integers/

// Runtime: 217 ms, faster than 42.47% of C++ online submissions for Maximum Split of Positive Even Integers.
// Memory Usage: 40.4 MB, less than 85.26% of C++ online submissions for Maximum Split of Positive Even Integers.

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum & 1)
            return {};

        vector<long long> res;
        long long sum = 0;
        long long i = 2;
        while (sum + i <= finalSum)
        {
            res.push_back(i);
            sum += i;
            i += 2;
        }
        if (sum < finalSum)
            res.back() += finalSum - sum;
        return res;
    }
};

// TLE
class Solution
{
    vector<long long> tmp;
    vector<long long> res;

    void split(long long finalSum, long long splitNum)
    {
        if (finalSum < splitNum)
            return;

        if (finalSum == splitNum)
        {
            tmp.push_back(splitNum);
            if (tmp.size() > res.size())
                res = tmp;
            tmp.pop_back();
            return;
        }

        tmp.push_back(splitNum);
        split(finalSum - splitNum, splitNum + 2);
        tmp.pop_back();

        split(finalSum, splitNum + 2);
    }

public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum & 1)
            return {};
        split(finalSum, 2);
        return res;
    }
};