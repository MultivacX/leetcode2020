// 55. Jump Game

// Runtime: 12 ms, faster than 72.02% of C++ online submissions for Jump Game.
// Memory Usage: 9.8 MB, less than 97.37% of C++ online submissions for Jump Game.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size() && i <= farthest; ++i) {
            int cur = i + nums[i];
            farthest = max(farthest, cur);
        }
        return farthest >= nums.size() - 1;
    }
};