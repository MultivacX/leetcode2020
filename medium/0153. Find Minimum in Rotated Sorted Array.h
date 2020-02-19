// c

// Runtime: 4 ms, faster than 76.98% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 8.8 MB, less than 75.56% of C++ online submissions for Find Minimum in Rotated Sorted Array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            // printf("[%d]:%d - [%d]:%d - [%d]:%d\n", begin, nums[begin], mid, nums[mid], end - 1, nums[end - 1]);
            ans = min(ans, min(nums[mid], min(nums[begin], nums[end - 1])));
            if (nums[begin] > nums[mid]) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return ans;
    }
};