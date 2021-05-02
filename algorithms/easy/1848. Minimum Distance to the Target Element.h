// 1848. Minimum Distance to the Target Element
// https://leetcode.com/problems/minimum-distance-to-the-target-element/

// Runtime: 4 ms, faster than 90.00% of C++ online submissions for Minimum Distance to the Target Element.
// Memory Usage: 9.7 MB, less than 10.00% of C++ online submissions for Minimum Distance to the Target Element.
    
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            if (nums[i] == target)
                ans = min(ans, abs(start - i));
        return ans;
    }
};