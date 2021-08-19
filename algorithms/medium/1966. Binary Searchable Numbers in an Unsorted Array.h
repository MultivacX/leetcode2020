// 1966. Binary Searchable Numbers in an Unsorted Array
// https://leetcode.com/problems/binary-searchable-numbers-in-an-unsorted-array/

// Runtime: 68 ms, faster than 93.91% of C++ online submissions for Binary Searchable Numbers in an Unsorted Array.
// Memory Usage: 49.1 MB, less than 26.96% of C++ online submissions for Binary Searchable Numbers in an Unsorted Array.
    
class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 1;
        
        vector<int> max_nums(n), min_nums(n);
        
        max_nums[0] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            max_nums[i] = max(max_nums[i - 1], nums[i - 1]);
        }
        
        min_nums[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; --i) {
            min_nums[i] = min(min_nums[i + 1], nums[i + 1]);
        }
        
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (max_nums[i] < nums[i] && nums[i] < min_nums[i]) {
                ++k;
            }
        }
        return k;
    }
};