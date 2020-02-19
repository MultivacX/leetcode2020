// 154. Find Minimum in Rotated Sorted Array II

// Runtime: 4 ms, faster than 98.40% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
// Memory Usage: 9 MB, less than 37.50% of C++ online submissions for Find Minimum in Rotated Sorted Array II.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            while (begin < end && nums[begin] == nums[end - 1]) {
                ans = min(ans, nums[begin]);
                ++begin;
                --end;
            }
            if (begin >= end) 
                break;
            
            // nums[begin] != nums[end - 1]
            int mid = begin + (end - begin) / 2;
            if (nums[begin] == nums[mid]) {
                ans = min(ans, nums[mid]);
                begin = mid + 1;
            } else if (nums[mid] == nums[end - 1]) {
                ans = min(ans, nums[mid]);
                end = mid;
            } else {
                ans = min(ans, min(nums[mid], min(nums[begin], nums[end - 1])));
                if (nums[begin] > nums[mid]) {
                    end = mid;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return ans;
    }
};