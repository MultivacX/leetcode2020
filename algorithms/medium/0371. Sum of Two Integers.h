// 371. Sum of Two Integers

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Sum of Two Integers.

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        for (int i = 0; i < 32; ++i) {
            bool a1 = a & (1 << i);
            bool b1 = b & (1 << i);
            if (a1 && b1) {
                if (carry) sum |= 1 << i;
                carry = 1;
            } else if (a1 || b1) {
                if (!carry) sum |= 1 << i;
                else carry = 1;
            } else if (carry) {
                sum |= 1 << i;
                carry = 0;
            }
        }
        return sum;
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        int c = 0, carry = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 1 << i;
            int bit_a = (a & bit) ? 1 : 0;
            int bit_b = (b & bit) ? 1 : 0;
            if (bit_a & bit_b) {
                // 1 1
                c |= carry ? bit : 0;
                carry = 1;
            } else if (bit_a | bit_b) {
                // 1 0
                c |= carry ? 0 : bit;
                carry = carry ? 1 : 0;
            } else {
                // 0 0
                c |= carry ? bit : 0;
                carry = 0;
            }
        }
        return c;
    }
};