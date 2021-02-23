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


class Solution {
    int find(const vector<int>& nums, int i, int j) {
        // [i, j)
        int val = nums[i];
        while (i < j - 1 && nums[i] == nums[j - 1]) ++i, --j;
        if (nums[i] <= nums[j - 1]) return min(val, nums[i]);
        int m = i + (j - i) / 2;
        return min(val, min(find(nums, i, m), find(nums, m, j)));
    }
    
public:
    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size());
    }
};