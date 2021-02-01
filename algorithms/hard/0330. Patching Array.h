// 330. Patching Array
// https://leetcode.com/problems/patching-array/

// Runtime: 8 ms, faster than 96.05% of C++ online submissions for Patching Array.
// Memory Usage: 11.7 MB, less than 79.84% of C++ online submissions for Patching Array.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        int64_t exclusive = 1;
        int i = 0;
        // [0, exclusive) formed
        // try to form exclusive
        while (exclusive <= n) {
            // use nums[i] to form exclusive
            if (i < nums.size() && exclusive >= (int64_t)nums[i]) {
                exclusive += nums[i++];
            } else {
                ++patches;
                exclusive += exclusive;
            }
        }
        return patches;
    }
};