// 280. Wiggle Sort
// https://leetcode.com/problems/wiggle-sort/

// Runtime: 32 ms, faster than 9.92% of C++ online submissions for Wiggle Sort.
// Memory Usage: 14.1 MB, less than 21.40% of C++ online submissions for Wiggle Sort.
    
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int N = nums.size();
        for (int i = 1; i + 1 < N; i += 2)
            swap(nums[i], nums[i + 1]);
    }
};