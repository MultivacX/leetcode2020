// 209. Minimum Size Subarray Sum

// Runtime: 8 ms, faster than 97.06% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Minimum Size Subarray Sum.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        
        int idx = 0;
        int sum = nums[0];
        if (sum >= s) return 1;
        
        int ans = n + 1;
        for (int i = 1; i < n && ans != 1; ++i) {
            sum += nums[i];
            while (sum >= s && idx <= s) {
                ans = min(ans, i - idx + 1);
                sum -= nums[idx++];
            }
        }
        return ans > n ? 0 : ans;
    }
};