// 2370. Longest Ideal Subsequence
// https://leetcode.com/problems/longest-ideal-subsequence/

// Runtime: 117 ms, faster than 77.67% of C++ online submissions for Longest Ideal Subsequence.
// Memory Usage: 10.2 MB, less than 79.71% of C++ online submissions for Longest Ideal Subsequence.

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        const int n = s.length();
        vector<int> res(26);
        for (int i = 0; i < n; ++i)
        {
            const int x = s[i] - 'a';
            const int L = max(0, x - k);
            const int R = min(25, x + k);
            // cout << L << " - " << R;
            int l = res[x];
            for (int j = L; j <= R; ++j)
                l = max(l, res[j] + 1);
            // cout << "  " << res[x] << "  " << l << endl;
            res[x] = l;
        }
        return *max_element(res.begin(), res.end());
    }
};