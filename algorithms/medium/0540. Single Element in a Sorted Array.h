// 540. Single Element in a Sorted Array

// Runtime: 12 ms, faster than 55.82% of C++ online submissions for Single Element in a Sorted Array.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Single Element in a Sorted Array.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            if (begin == end - 1)
                return nums[begin];
            int mid = begin + (end - begin) / 2;
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            
            // [begin, mid)
            int l_cnt = mid - begin;
            if (l_cnt & 1) {
                if (nums[mid - 1] == nums[mid]) begin = mid + 1;
                else end = mid;
            } else {
                if (nums[mid] == nums[mid + 1]) begin = mid + 2;
                else end = mid - 1;
            }
        }
        return 0;
    }
};