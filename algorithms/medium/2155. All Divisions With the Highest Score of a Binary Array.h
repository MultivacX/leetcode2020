// 2155. All Divisions With the Highest Score of a Binary Array
// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

// Runtime: 713 ms, faster than 55.93% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.
// Memory Usage: 286.5 MB, less than 80.09% of C++ online submissions for All Divisions With the Highest Score of a Binary Array.

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int l = 0, r = accumulate(nums.cbegin(), nums.cend(), 0);
        const int n = nums.size();

        int score = r;
        vector<int> res{0};
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                ++l;
            else
                --r;

            if (score < l + r)
            {
                score = l + r;
                res.clear();
                res.push_back(i + 1);
            }
            else if (score == l + r)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};