// 1281. Subtract the Product and Sum of Digits of an Integer

// Runtime: 4 ms, faster than 52.24% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while (n) {
            int x = n % 10;
            p *= x;
            s += x;
            n /= 10;
        }
        return p - s;
    }
};