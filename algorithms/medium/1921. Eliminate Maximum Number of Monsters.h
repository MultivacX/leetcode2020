// 1921. Eliminate Maximum Number of Monsters
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

// Runtime: 466 ms, faster than 5.52% of C++ online submissions for Eliminate Maximum Number of Monsters.
// Memory Usage: 83 MB, less than 71.80% of C++ online submissions for Eliminate Maximum Number of Monsters.

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        const int n = dist.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return dist[i] * speed[j] < dist[j] * speed[i]; });

        int k = 0;
        for (int m = 0; m < n; ++m, ++k)
        {
            int i = idx[m];
            // cout << i << " : ";
            int pos = dist[i] - speed[i] * m;
            // cout << dist[i] << " - " << speed[i] << " * " << m << " = " << pos << '\n';
            if (pos <= 0)
                break;
        }
        // cout << '\n';
        return k;
    }
};