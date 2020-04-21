// 673. Number of Longest Increasing Subsequence

// Runtime: 52 ms, faster than 72.09% of C++ online submissions for Number of Longest Increasing Subsequence.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Number of Longest Increasing Subsequence.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;
        
        int longest = 0;
        int ans = 0;
        vector<pair<int, int>> v(n, {0, 0});
        for (int i = 0; i < n; ++i) {
            int len = 0;
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (len == v[j].first) cnt += v[j].second;
                    else if (len < v[j].first) len = v[j].first, cnt = v[j].second;   
                }
            }
            v[i].first = ++len;
            v[i].second = cnt == 0 ? 1 : cnt;
            longest = max(longest, len);
        }
        for (int i = 0; i < n; ++i) {
            if (v[i].first == longest) ans += v[i].second;
        }
        return ans;
    }
};