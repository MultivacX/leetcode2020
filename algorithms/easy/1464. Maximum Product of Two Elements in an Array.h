// 1464. Maximum Product of Two Elements in an Array
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// Runtime: 16 ms, faster than 25.34% of C++ online submissions for Maximum Product of Two Elements in an Array.
// Memory Usage: 9.8 MB, less than 98.85% of C++ online submissions for Maximum Product of Two Elements in an Array.
    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1];
        if (a > b) swap(a, b);
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] >= b) {
                a = b;
                b = nums[i];
            } else if (nums[i] > a) {
                a = nums[i];
            }
        }
        return (a - 1) * (b - 1);
    }
};