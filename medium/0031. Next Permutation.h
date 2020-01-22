// 31. Next Permutation

// Runtime: 16 ms, faster than 10.40% of C++ online submissions for Next Permutation.
// Memory Usage: 8.5 MB, less than 97.85% of C++ online submissions for Next Permutation.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) --i;
        if (i == 0) {
            int j = nums.size() - 1;
            while (i < j) swap(nums[i++], nums[j--]);
        } else {
            int j = i - 1;
            i = nums.size() - 1;
            while (nums[i] <= nums[j]) --i;
            swap(nums[j], nums[i]);
            sort(nums.begin() + j + 1, nums.end());
            /* or:
            // i = j + 1;
            // j = nums.size() - 1;
            // while (i < j) swap(nums[i++], nums[j--]);*/
        }
    }
};