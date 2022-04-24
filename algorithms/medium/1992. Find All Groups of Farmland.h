// 1992. Find All Groups of Farmland
// https://leetcode.com/problems/find-all-groups-of-farmland/

// Runtime: 222 ms, faster than 58.40% of C++ online submissions for Find All Groups of Farmland.
// Memory Usage: 62.1 MB, less than 69.72% of C++ online submissions for Find All Groups of Farmland.

class Solution
{
    void find(vector<vector<int> > &land, int i, int j, int &r, int &c)
    {
        if (i < 0 || i >= land.size())
            return;
        if (j < 0 || j >= land[0].size())
            return;
        if (land[i][j] != 1)
            return;

        land[i][j] = -1;
        r = max(i, r);
        c = max(j, c);
        find(land, i - 1, j, r, c);
        find(land, i + 1, j, r, c);
        find(land, i, j - 1, r, c);
        find(land, i, j + 1, r, c);
    }

public:
    vector<vector<int> > findFarmland(vector<vector<int> > &land)
    {
        const int m = land.size();
        const int n = land[0].size();
        vector<vector<int> > ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (land[i][j] != 1)
                    continue;
                int r = i, c = j;
                find(land, i, j, r, c);
                ans.push_back({i, j, r, c});
            }
        }
        return ans;
    }
};