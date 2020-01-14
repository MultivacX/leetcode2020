// 713. Subarray Product Less Than K

// Runtime: 124 ms, faster than 92.57% of C++ online submissions for Subarray Product Less Than K.
// Memory Usage: 18.2 MB, less than 90.00% of C++ online submissions for Subarray Product Less Than K.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int n = nums.size();
        int ans = 0;
        int i = -1;
        int product = -1;
        for (int j = 0; j < n; ++j) {
            if (nums[j] >= k) {
                if (i > -1) {
                    int cnt = j - i;
                    ans += cnt * (cnt + 1) / 2;
                    i = -1;
                    product = -1;
                }
            } else if (product < 0) {
                i = j;
                product = nums[j];
            } else if (product * nums[j] < k) {
                product *= nums[j];
            } else {
                while (product * nums[j] >= k) {
                    int cnt = j - i;
                    ans += cnt;
                    product /= nums[i];
                    ++i;
                }
                product *= nums[j];
            }
        }
        if (i > -1 && i < n) {
            int cnt = n - i;
            int tmp = cnt + 1;
            if (cnt % 2 == 0) cnt /= 2;
            else tmp /= 2;
            ans += cnt * tmp;
        }
        return ans;
    }
};