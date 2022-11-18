// 2432. The Employee That Worked on the Longest Task
// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

// Runtime: 181 ms, faster than 23.44% of C++ online submissions for The Employee That Worked on the Longest Task.
// Memory Usage: 35.5 MB, less than 47.89% of C++ online submissions for The Employee That Worked on the Longest Task.

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int id = logs[0][0], t = logs[0][1];
        for (int i = 1, start = t; i < logs.size(); ++i)
        {
            int x = logs[i][1] - start;
            if (x > t)
                id = logs[i][0], t = x;
            else if (x == t)
                id = min(id, logs[i][0]);
            start = logs[i][1];
        }
        return id;
    }
};