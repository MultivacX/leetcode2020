// 1493. Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

// Runtime: 132 ms, faster than 43.01% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.
// Memory Usage: 36.6 MB, less than 56.67% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return 0;
        
        vector<pair<int, int>> v{{nums[0], 1}};
        for (int i = 1; i < N; ++i) {
            if (v.back().first == nums[i]) ++v.back().second;
            else v.push_back({nums[i], 1});
        }
        
        if (v.size() == 1) return v[0].first == 0 ? 0 : v[0].second - 1;
        
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first == 1) {
                ans = max(ans, v[i].second);
                if (i + 2 < v.size() && v[i + 1].second == 1)
                    ans = max(ans, v[i].second + v[i + 2].second);
            }
        }
        return ans;
    }
};