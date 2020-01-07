// 283. Move Zeroes

// Runtime: 12 ms, faster than 97.08% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Move Zeroes.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (zero < 0) {
                if (nums[i] == 0) {
                    zero = i;
                }
            } else if (nums[i] != 0) {
                nums[zero] = nums[i];
                nums[i] = 0;
                do {
                    ++zero;
                } while (nums[zero]);
            }
        }
    }
};