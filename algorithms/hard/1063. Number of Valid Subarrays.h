// 1063. Number of Valid Subarrays
// https://leetcode.com/problems/number-of-valid-subarrays/

// Runtime: 72 ms, faster than 88.51% of C++ online submissions for Number of Valid Subarrays.
// Memory Usage: 44.9 MB, less than 40.23% of C++ online submissions for Number of Valid Subarrays.
    
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        const int N = nums.size();
        // indices[i]: min(distance(i, j))
        // i < j && nums[i] > nums[j]
        vector<int> indices(N, N);
        int ans = 1;
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && nums[i] <= nums[j])
                j = indices[j];
            indices[i] = j;
            ans += indices[i] - i;
        }
        return ans;
    }
};