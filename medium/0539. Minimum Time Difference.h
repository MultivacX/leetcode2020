// 539. Minimum Time Difference

// Runtime: 32 ms, faster than 28.85% of C++ online submissions for Minimum Time Difference.
// Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Minimum Time Difference.

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vals;
        for (const auto& s : timePoints) {
            int h = (s[0] - '0') * 10 + (s[1] - '0');
            int m = (s[3] - '0') * 10 + (s[4] - '0');
            vals.push_back(h * 60 + m);
            vals.push_back(vals.back() + 1440);
        }
        sort(begin(vals), end(vals));
        int ans = vals[1] - vals[0];
        for (int i = 2; i < vals.size(); ++i)
            ans = min(ans, vals[i] - vals[i - 1]);
        return ans;
    }
};