// 1918. Kth Smallest Subarray Sum
// https://leetcode.com/problems/kth-smallest-subarray-sum/

// Runtime: 128 ms, faster than 38.95% of C++ online submissions for Kth Smallest Subarray Sum.
// Memory Usage: 30.5 MB, less than 88.42% of C++ online submissions for Kth Smallest Subarray Sum.
    
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int l = *min_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 1);
        while (l < r) {
            int m = l + (r - l) / 2;
            
            // sliding window
            int i = 0, j = 0, cnt = 0, sum = 0;
            while (i < n) {
                if (sum + nums[i] <= m) {
                    sum += nums[i++];
                    cnt += i - j;
                } else {
                    sum -= nums[j++];
                }
            }
            
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};