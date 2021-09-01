// 1979. Find Greatest Common Divisor of Array
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

// Runtime: 4 ms, faster than 90.56% of C++ online submissions for Find Greatest Common Divisor of Array.
// Memory Usage: 12.3 MB, less than 93.56% of C++ online submissions for Find Greatest Common Divisor of Array.
    
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(begin(nums), end(nums)), *max_element(begin(nums), end(nums)));
    }
};