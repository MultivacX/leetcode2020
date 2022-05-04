// 2091. Removing Minimum and Maximum From Array
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

// Runtime: 353 ms, faster than 5.04% of C++ online submissions for Removing Minimum and Maximum From Array.
// Memory Usage: 88.3 MB, less than 39.54% of C++ online submissions for Removing Minimum and Maximum From Array.

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        const int n = nums.size();
        if (n <= 2)
            return n;

        int a = 0, b = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[a] > nums[i])
                a = i;
            if (nums[b] < nums[i])
                b = i;
        }

        if (a > b)
            swap(a, b);
        // cout << a << ' ' << b << endl;
        return min(a + 1 + n - b, min(b + 1, n - a));
    }
};