// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Runtime: 28 ms, faster than 86.16% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 88.8 MB, less than 95.42% of C++ online submissions for Median of Two Sorted Arrays.
    
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        const int t = (m + n + 1) / 2;
        int i = 0, j = 0, k = 0, ans = 0;
        while (k < t) {
            bool is_nums1 = i < m && (j >= n || (j < n && nums1[i] <= nums2[j]));
            is_nums1 ? ++i : ++j;
            
            if (++k != t) continue;
            
            ans = is_nums1 ? nums1[i - 1] : nums2[j - 1];
            if ((m + n) % 2) return ans;
            
            if (i < m && j < n) ans += min(nums1[i], nums2[j]);
            else if (i < m) ans += nums1[i];
            else ans += nums2[j];
            return ans / 2.0;
        }
        return ans;
    }
};