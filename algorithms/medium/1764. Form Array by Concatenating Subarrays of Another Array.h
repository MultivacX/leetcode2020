// 1764. Form Array by Concatenating Subarrays of Another Array
// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Form Array by Concatenating Subarrays of Another Array.
// Memory Usage: 13.3 MB, less than 83.33% of C++ online submissions for Form Array by Concatenating Subarrays of Another Array.
    
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        const int n = groups.size();
        const int m = nums.size();
        int i = 0, j = 0, k = 0;
        while (i < n && k < m) {
            if (groups[i][j] == nums[k]) {
                ++j;
                if (groups[i].size() == j) {
                    if (++i == n) return true;
                    j = 0;
                }
            } else {
                k -= j;
                j = 0;
            }
            ++k;
        }
        return false;
    }
};