// 334. Increasing Triplet Subsequence

// Runtime: 8 ms, faster than 35.89% of C++ online submissions for Increasing Triplet Subsequence.
// Memory Usage: 10.2 MB, less than 5.88% of C++ online submissions for Increasing Triplet Subsequence.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3) return false;
        
        int i = -1;
        int j = -1;
        for (int k = 0; k < N; ++k) {
            if (i < 0 || nums[i] >= nums[k]) i = k;
            else if (j < 0 || nums[j] >= nums[k]) j = k;
            else return true;
        }
        
        return false;
    }
};