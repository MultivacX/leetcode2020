// 1780. Check if Number is a Sum of Powers of Three
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Number is a Sum of Powers of Three.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Check if Number is a Sum of Powers of Three.
    
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int r = n % 3;
            if (r == 2) return false;
            n /= 3;
        }
        return true;
    }
};