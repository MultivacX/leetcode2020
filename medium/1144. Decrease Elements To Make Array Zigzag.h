// 1144. Decrease Elements To Make Array Zigzag
// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decrease Elements To Make Array Zigzag.
// Memory Usage: 7.4 MB, less than 25.69% of C++ online submissions for Decrease Elements To Make Array Zigzag.

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int N = nums.size();
        int e = 0;
        int o = 0;
        for (int i = 0; i < N; ++i) {
            int v = min(i == 0 ? 1001 : nums[i - 1], i == N - 1 ? 1001 : nums[i + 1]);
            int moves = v > nums[i] ? 0 : (nums[i] - v + 1);
            if (i % 2 == 0) e += moves;
            else o += moves;
        }
        return min(e, o);
    }
};
