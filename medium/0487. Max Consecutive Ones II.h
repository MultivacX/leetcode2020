// 487. Max Consecutive Ones II
// https://leetcode.com/problems/max-consecutive-ones-ii/

// Runtime: 80 ms, faster than 67.44% of C++ online submissions for Max Consecutive Ones II.
// Memory Usage: 36.5 MB, less than 29.67% of C++ online submissions for Max Consecutive Ones II.
    
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        for (int i = 0, cur = 0; i < N; ++i) {
            if (nums[i] == 0) {
                nums[i] = 10000 + cur;
                cur = 0;
            } else if (ans < ++cur) {
                ans = cur;
            }
        }
        for (int i = N - 1, cur = 0; i >= 0; --i) {
            if (nums[i] > 1) {
                ans = max(ans, cur + nums[i] - 9999);
                nums[i] = 0;
                cur = 0;
            } else if (ans < ++cur) {
                ans = cur;
            }
        }
        return ans;
    }
};