// 2420. Find All Good Indices
// https://leetcode.com/problems/find-all-good-indices/

// Runtime: 402 ms, faster than 20.21% of C++ online submissions for Find All Good Indices.
// Memory Usage: 86.2 MB, less than 83.83% of C++ online submissions for Find All Good Indices.

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> after(n);
        for (int i = n - 2, l = 1; i >= 0; --i)
        {
            // cout << i << ':' << l << ' ';

            after[i] = l;
            l = nums[i] <= nums[i + 1] ? l + 1 : 1;
        }
        // cout << endl;

        vector<int> res;
        for (int i = 1, l = 1; i < n; ++i)
        {
            // cout << i << ':' << l << ' ';

            if (l >= k && after[i] >= k)
                res.push_back(i);
            l = nums[i - 1] >= nums[i] ? l + 1 : 1;
        }
        return res;
    }
};