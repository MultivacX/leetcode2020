// 88. Merge Sorted Array

// Runtime: 8 ms, faster than 9.39% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.2 MB, less than 6.52% of C++ online submissions for Merge Sorted Array.

// Time Complexity: O(nums1.size()+nums2.size()).
// Space Complexity: O(1).

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};