// 2501. Longest Square Streak in an Array

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        int res = 0;
        for (int i : nums)
        {
            int j = sqrt(i);
            if (j * j != i)
            {
                m[i] = 1;
                continue;
            }

            auto it = m.find(j);
            if (it == m.end())
                m[i] = 1;
            else
            {
                m[i] = it->second + 1;
                res = max(res, m[i]);
                // cout << i << ": " << m[i] << endl;
            }
        }
        return res < 2 ? -1 : res;
    }
};