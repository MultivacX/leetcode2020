// 80. Remove Duplicates from Sorted Array II

// Runtime: 12 ms, faster than 79.08% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 11 MB, less than 5.26% of C++ online submissions for Remove Duplicates from Sorted Array II.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return N;
        
        int i = 1;
        for (int j = 2; j < N; ++j) {
            if (nums[i - 1] == nums[i]) {
                if (nums[i] < nums[j]) {
                    nums[++i] = nums[j];
                }
            } else {
                if (nums[i] <= nums[j]) {
                    nums[++i] = nums[j];
                }
            }
        }
        return i + 1;
    }
};