// 673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        int max_len = 1;
        vector<int> len(n, 1);
        vector<int> dp{nums[0]};
        for (int i = 1; i < n; ++i) {
            auto it = upper_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
                len[i] = dp.size();
            } else {
                *it = nums[i];
                len[i] = it - dp.begin() + 1;
            }
            max_len = max(max_len, len[i]);
        }
        return count(len.begin(), len.end(), max_len);
    }
};