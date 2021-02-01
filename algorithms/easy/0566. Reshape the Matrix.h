// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/

// Runtime: 20 ms, faster than 87.74% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 11.7 MB, less than 62.67% of C++ online submissions for Reshape the Matrix.

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        const int R = nums.size();
        const int C = nums[0].size();
        if (R * C != r * c) return nums;
        if (R == r) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int k = 0; k < R * C; ++k) 
            ans[k/c][k%c] = nums[k/C][k%C];
        return ans;
    }
};