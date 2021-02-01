// 485. Max Consecutive Ones

// Runtime: 32 ms, faster than 94.36% of C++ online submissions for Max Consecutive Ones.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Max Consecutive Ones.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int L = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (L < 0) L = i;
                cnt = max(cnt, i - L + 1);
            } else {
                L = -1;
            }
        }
        return cnt;
    }
};