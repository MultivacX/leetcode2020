// 33. Search in Rotated Sorted Array

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Search in Rotated Sorted Array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int mid = begin + ((end - begin) >> 1);
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) {
                if (nums[begin] < nums[mid] && target >= nums[begin]) end = mid;
                else if (nums[mid] < nums[end - 1]) end = mid;
                else begin = mid + 1;
            } else {
                // nums[mid] < target
                if (nums[mid] < nums[end - 1] && target <= nums[end - 1]) begin = mid + 1;
                else if (nums[begin] < nums[mid]) begin = mid + 1;
                else end = mid;
            }
        }
        return -1;
    }
};