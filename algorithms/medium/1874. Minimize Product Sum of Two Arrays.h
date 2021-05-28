// 1874. Minimize Product Sum of Two Arrays
// https://leetcode.com/problems/minimize-product-sum-of-two-arrays/

// Runtime: 228 ms, faster than 100.00% of C++ online submissions for Minimize Product Sum of Two Arrays.
// Memory Usage: 105.4 MB, less than 100.00% of C++ online submissions for Minimize Product Sum of Two Arrays.
    
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(rbegin(nums2), rend(nums2));
        int ans = 0;
        const int n = nums1.size();
        for (int i = 0; i < n; ++i)
            ans += nums1[i] * nums2[i];
        return ans;
    }
};