// 81. Search in Rotated Sorted Array II

// Runtime: 8 ms, faster than 63.50% of C++ online submissions for Search in Rotated Sorted Array II.
// Memory Usage: 9.1 MB, less than 8.33% of C++ online submissions for Search in Rotated Sorted Array II.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }
    
    bool search(vector<int>& nums, int begin, int end, int target) {
        while (begin < end && nums[begin] == nums[end - 1]) {
            if (nums[begin] == target) 
                return true;
            ++begin;
            --end;
        }
        if (begin >= end) 
            return false;
        
        if (nums[begin] < nums[end - 1]) 
            return binary_search(nums.begin() + begin, nums.begin() + end, target);
        
        int middle = begin + ((end - begin) >> 1);
        cout << middle << endl;
        if (nums[middle] == target) 
            return true;
        
        return search(nums, begin, middle, target) || search(nums, middle + 1, end, target);
    }
};