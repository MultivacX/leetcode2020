// 1822. Sign of the Product of an Array
// https://leetcode.com/problems/sign-of-the-product-of-an-array/

// Runtime: 8 ms, faster than 71.43% of C++ online submissions for Sign of the Product of an Array.
// Memory Usage: 10.2 MB, less than 14.29% of C++ online submissions for Sign of the Product of an Array.
    
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i : nums)
            if (i == 0) return 0;
            else if (i < 0) ans *= -1;
        return ans;
    }
};