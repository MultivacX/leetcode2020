// 1359. Count All Valid Pickup and Delivery Options
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count All Valid Pickup and Delivery Options.
// Memory Usage: 5.8 MB, less than 67.29% of C++ online submissions for Count All Valid Pickup and Delivery Options.
    
class Solution {
public:
    int countOrders(int n) {
        int64_t f = 1;
        for (int i = 2; i <= n; ++i) {
            int64_t k = (i - 1) * 2 + 1;
            f = f * (1 + k) * k / 2 % 1000000007;
        }
        return f;
    }
};