// 1424. Diagonal Traverse II

// Runtime: 404 ms, faster than 94.62% of C++ online submissions for Diagonal Traverse II.
// Memory Usage: 82.1 MB, less than 100.00% of C++ online submissions for Diagonal Traverse II.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        const int ROWS = nums.size();
        int MAX_COLS = 0;
        for (const auto& row : nums) 
            MAX_COLS = max(MAX_COLS, (int)row.size());
        
        vector<vector<int>> diagonals(ROWS + MAX_COLS);
        for (int i = ROWS - 1; i >= 0; --i) 
            for (int j = 0; j < nums[i].size(); ++j) 
                diagonals[i + j].push_back(nums[i][j]);
            
        vector<int> ans;
        for (const auto& v : diagonals) 
            for (int i : v) 
                ans.push_back(i);
        return ans;
    }
};