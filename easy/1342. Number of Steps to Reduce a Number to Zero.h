// 1342. Number of Steps to Reduce a Number to Zero
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
// Memory Usage: 6.2 MB, less than 87.60% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
    
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num) {
            num & 1 ? num -= 1 : num >>= 1;
            ++step;
        }
        return step;
    }
};