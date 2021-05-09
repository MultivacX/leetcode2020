// 1855. Maximum Distance Between a Pair of Values
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

// Runtime: 140 ms, faster than 87.50% of C++ online submissions for Maximum Distance Between a Pair of Values.
// Memory Usage: 98.5 MB, less than 50.00% of C++ online submissions for Maximum Distance Between a Pair of Values.

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0, j = 0; j < nums2.size(); ++j) {
            while (i < nums1.size() && nums1[i] > nums2[j]) ++i;
            if (i == nums1.size()) break;
            ans = max(ans, j - i);
        }
        return ans;
    }
};