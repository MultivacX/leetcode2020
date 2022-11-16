// 2449. Minimum Number of Operations to Make Arrays Similar
// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

// Runtime: 676 ms, faster than 5.71% of C++ online submissions for Minimum Number of Operations to Make Arrays Similar.
// Memory Usage: 104.6 MB, less than 5.05% of C++ online submissions for Minimum Number of Operations to Make Arrays Similar.

class Solution
{
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        unordered_map<int, int> m;
        for (int t : target)
            ++m[t];

        int n = nums.size(), i = 0, j = 0;
        while (i < n)
        {
            if (m.count(nums[i]) && m[nums[i]] > 0)
            {
                --m[nums[i]];
                swap(nums[i], nums[n - 1]);
                --n;
            }
            else
            {
                ++i;
            }
        }
        if (n == 0)
            return 0;

        i = 0;
        for (auto [num, cnt] : m)
        {
            while (cnt)
            {
                target[i++] = num;
                --cnt;
            }
        }

        sort(nums.begin(), nums.begin() + n);
        sort(target.begin(), target.begin() + n);

        i = 0;
        uint64_t plus = 0, minus = 0;
        while (i < n && j < n)
        {
            if (nums[i] % 2 == 0)
            {
                ++i;
                continue;
            }
            if (target[j] % 2 == 0)
            {
                ++j;
                continue;
            }
            int offset = nums[i] - target[j];
            offset > 0 ? plus += offset : minus += offset;
            ++i, ++j;
        }

        i = j = 0;
        while (i < n && j < n)
        {
            if (nums[i] % 2)
            {
                ++i;
                continue;
            }
            if (target[j] % 2)
            {
                ++j;
                continue;
            }
            int offset = nums[i] - target[j];
            offset > 0 ? plus += offset : minus += offset;
            ++i, ++j;
        }

        return plus / 2;
    }
};