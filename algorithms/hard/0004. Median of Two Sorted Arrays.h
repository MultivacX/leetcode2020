// 4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        const int M = nums1.size();
        const int N = nums2.size();
        const int L = M + N - 1;
        const int K = L / 2;
        // L is odd : nums[L/2] 
        // L is even : (nums[L/2] + nums[L/2+1])/2
        // i + j + 1 == K
        
        int min_i = 0;
        int max_i = M;
        while (true) {
            if (min_i < max_i) {
                int i = min_i + (max_i - min_i) / 2;
                int j = K - i - 1;
                if (j < 0) {}
                else if (j >= N) {} 
                else {
                    
                }
            } else if (max_i == 0) {
                 
            } else {

            }
        }
    }
};