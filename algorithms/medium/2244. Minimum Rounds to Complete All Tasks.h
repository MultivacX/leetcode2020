// 2244. Minimum Rounds to Complete All Tasks
// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

// Runtime: 249 ms, faster than 89.98% of C++ online submissions for Minimum Rounds to Complete All Tasks.
// Memory Usage: 94.8 MB, less than 96.74% of C++ online submissions for Minimum Rounds to Complete All Tasks.

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        const int n = tasks.size();
        if (n == 1)
            return -1;
        sort(tasks.begin(), tasks.end());
        int res = 0;
        for (int i = 1, k = 1; i < n; ++i)
        {
            if (tasks[i] == tasks[i - 1])
            {
                ++k;
                if (i + 1 == n)
                    res += k / 3 + (k % 3 ? 1 : 0);
            }
            else if (k == 1 || i + 1 == n)
            {
                return -1;
            }
            else
            {
                res += k / 3 + (k % 3 ? 1 : 0);
                k = 1;
            }
        }
        return res;
    }
};