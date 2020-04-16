// 673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;
        
        int longest = 0;
        int ans = 0;
        // {begin num, {len, cnt}}
        map<int, pair<int, int>> m;
        for (int i = n - 1; i >= 0; --i) {
            auto it = m.upper_bound(nums[i]);
            int len = 1;
            int cnt = 1;
            while (it != m.end()) {
                if (len < 1 + it->second.first) {
                    len = 1 + it->second.first;
                    cnt = it->second.second;
                } else if (len == 1 + it->second.first) {
                    cnt += it->second.second;
                }
                ++it;
            }
            m[nums[i]].first = len;
            m[nums[i]].second = cnt;
            
            if (longest < len) {
                longest = len;
                ans = cnt;
            } else if (longest == len) {
                longest = len;
                ans += cnt;
            }
        }
        return ans;
    }
};