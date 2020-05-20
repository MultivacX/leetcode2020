// 4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        const int M = nums1.size();
        const int N = nums2.size();
        
        int min_i = 0;
        int max_i = M;
        while (min_i < max_i) {
            int i = min_i + (max_i - min_i) / 2;
            // int j = (M + N) / 2 - i - 1;

            if (i == 0) {

            } else if (i == M - 1) {

            }
        }
    }
};