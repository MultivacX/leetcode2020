// 747. Largest Number At Least Twice of Others

// Runtime: 4 ms, faster than 66.20% of C++ online submissions for Largest Number At Least Twice of Others.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Largest Number At Least Twice of Others.

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest_idx = max_element(begin(nums), end(nums)) - begin(nums);
        for (int i = 0; i < nums.size(); ++i) 
            if (i != largest_idx && nums[i] * 2 > nums[largest_idx]) 
                return -1;
        return largest_idx;
    }
};