// 1708. Largest Subarray Length K
// https://leetcode.com/problems/largest-subarray-length-k/

// Runtime: 300 ms, faster than 71.37% of C++ online submissions for Largest Subarray Length K.
// Memory Usage: 72.3 MB, less than 78.82% of C++ online submissions for Largest Subarray Length K.
    
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        const int N = nums.size();
        int i = 0;
        for (int j = 1; j + k <= N; ++j) {
            for (int x = 0; x < k; ++x) {
                if (nums[i + x] != nums[j + x]) {
                    if (nums[i + x] < nums[j + x]) i = j;
                    break;
                }
            }
        }
        return vector<int>(begin(nums) + i, begin(nums) + i + k);
    }
};