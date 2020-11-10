// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/

// Runtime: 28 ms, faster than 83.76% of C++ online submissions for Lemonade Change.
// Memory Usage: 17.2 MB, less than 5.91% of C++ online submissions for Lemonade Change.

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changes[] = {0, 0};
        for (int b : bills) {
            if (b == 5) ++changes[0];
            else if (b == 10) {
                if (--changes[0] < 0)
                    return false;
                ++changes[1];
            } else {
                if (changes[0] - 1 >= 0 && changes[1] - 1 >= 0) --changes[0], --changes[1];
                else if (changes[0] - 3 >= 0) changes[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};