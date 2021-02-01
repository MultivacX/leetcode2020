// 1537. Get the Maximum Score
// https://leetcode.com/problems/get-the-maximum-score/

// Runtime: 168 ms, faster than 94.76% of C++ online submissions for Get the Maximum Score.
// Memory Usage: 56.1 MB, less than 59.69% of C++ online submissions for Get the Maximum Score.

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int M = nums1.size();
        const int N = nums2.size();
        int64_t sum = 0;
        int64_t sum1 = 0;
        int64_t sum2 = 0;
        int i = 0; 
        int j = 0;
        while (i < M && j < N) {
            if (nums1[i] == nums2[j]) {
                sum1 += nums1[i++];
                sum2 += nums2[j++];
                sum += max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
            } else if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else {
                sum2 += nums2[j++];
            }
        }
        while (i < M) sum1 += nums1[i++];
        while (j < N) sum2 += nums2[j++];
        sum += max(sum1, sum2);
        return sum % 1000000007;
    }
};