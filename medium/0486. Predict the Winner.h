// 486. Predict the Winner

// Runtime: 4 ms, faster than 51.82% of C++ online submissions for Predict the Winner.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Predict the Winner.

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return choose(nums, 0, nums.size() - 1, 0, 0, 1);
    }
    
    bool choose(vector<int>& nums, int i, int j, int score1, int score2, int player) {
        if (i == j)
            return player == 1 ? score1 + nums[i] >= score2 : score1 < score2 + nums[i];
        
        if (player == 1)
            return !choose(nums, i + 1, j, score1 + nums[i], score2, 2) || !choose(nums, i, j - 1, score1 + nums[j], score2, 2);
        else
            return !choose(nums, i + 1, j, score1, score2 + nums[i], 1) || !choose(nums, i, j - 1, score1, score2 + nums[j], 1);
    }
};