// 581. Shortest Unsorted Continuous Subarray

// Runtime: 48 ms, faster than 34.74% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage: 10.7 MB, less than 47.62% of C++ online submissions for Shortest Unsorted Continuous Subarray.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        vector<int> sorted(nums);
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n && sorted[i] == nums[i]) ++i;
        int j = n - 1;
        while (j > i && sorted[j] == nums[j]) --j;
        // printf("%d - %d\n", i, j);
        return i >= j ? 0 : j - i + 1;
    }
};