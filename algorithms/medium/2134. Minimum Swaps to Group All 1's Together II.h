// 2134. Minimum Swaps to Group All 1's Together II
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// Runtime: 218 ms, faster than 58.10% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// Memory Usage: 80.4 MB, less than 92.43% of C++ online submissions for Minimum Swaps to Group All 1's Together II.

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        const int L = accumulate(nums.cbegin(), nums.cend(), 0);
        const int N = nums.size();
        int k = accumulate(nums.cbegin(), nums.cbegin() + L, 0);
        int res = L - k;
        for (int i = 0; i < N; ++i)
        {
            k -= nums[i];
            k += nums[(i + L) % N];
            res = min(res, L - k);
        }
        return res;
    }
};