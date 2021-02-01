// 1099. Two Sum Less Than K
// Runtime: 4 ms, faster than 94.18% of C++ online submissions for Two Sum Less Than K.
// Memory Usage: 9.4 MB, less than 74.01% of C++ online submissions for Two Sum Less Than K.
    
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int i = 0, j = nums.size() - 1;
        int ans = -1;
        while (i < j) {
            if (nums[i] + nums[j] >= k) --j;
            else ans = max(ans, nums[i++] + nums[j]);
        }
        return ans;
    }
};