// 2150. Find All Lonely Numbers in the Array
// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

// Runtime: 615 ms, faster than 54.49% of C++ online submissions for Find All Lonely Numbers in the Array.
// Memory Usage: 167.1 MB, less than 77.24% of C++ online submissions for Find All Lonely Numbers in the Array.

class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (int i : nums)
            ++cnt[i];

        vector<int> ans;
        for (int i : nums)
        {
            // cout << i << " " << cnt[i] << endl;
            if (cnt[i] > 1)
                continue;
            if (cnt.count(i - 1) > 0)
                continue;
            if (cnt.count(i + 1) > 0)
                continue;
            ans.push_back(i);
        }
        return ans;
    }
};