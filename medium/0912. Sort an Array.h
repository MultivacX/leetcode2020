// 912. Sort an Array

// Runtime: 44 ms, faster than 95.16% of C++ online submissions for Sort an Array.
// Memory Usage: 15.9 MB, less than 22.22% of C++ online submissions for Sort an Array.

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size());
        return nums;
    }
    
    int p(vector<int>& nums, int begin, int end) {
        int pivot = nums[end - 1];
        int i = begin - 1;
        for (int j = begin; j < end - 1; ++j) {
            if (nums[j] < pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end - 1]);
        return i + 1;
    }
    
    void sort(vector<int>& nums, int begin, int end) {
        if (begin >= end - 1) return;
        int i = p(nums, begin, end);
        sort(nums, begin, i);
        sort(nums, i + 1, end);
    }
};

// Runtime: 52 ms, faster than 90.01% of C++ online submissions for Sort an Array.
// Memory Usage: 15.6 MB, less than 22.22% of C++ online submissions for Sort an Array.

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums;
    }
};