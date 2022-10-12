// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

// Runtime: 873 ms, faster than 5.08% of C++ online submissions for Max Sum of a Pair With Equal Sum of Digits.
// Memory Usage: 60 MB, less than 94.01% of C++ online submissions for Max Sum of a Pair With Equal Sum of Digits.

class Solution
{
    static int sum(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

public:
    int maximumSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             {
            int sa = Solution::sum(a);
            int sb = Solution::sum(b);
            if (sa == sb) return a > b;
            return sa > sb; });

        // for (int i : nums) cout << i << ' '; cout << endl;

        const int n = nums.size();
        int res = -1;
        for (int i = 0; i + 1 < n; ++i)
            if (sum(nums[i]) == sum(nums[i + 1]))
                res = max(res, nums[i] + nums[i + 1]);
        return res;
    }
};