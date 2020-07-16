// 991. Broken Calculator
// https://leetcode.com/problems/broken-calculator/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Broken Calculator.
// Memory Usage: 6.1 MB, less than 18.42% of C++ online submissions for Broken Calculator.

class Solution {    
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (X < Y) {
            if (Y & 1) ++Y; 
            else Y >>= 1;
            ++ans;
        }
        return ans + X - Y;
    }
};