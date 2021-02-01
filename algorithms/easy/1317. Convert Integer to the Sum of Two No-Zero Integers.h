// 1317. Convert Integer to the Sum of Two No-Zero Integers
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Integer to the Sum of Two No-Zero Integers.
// Memory Usage: 6.7 MB, less than 8.13% of C++ online submissions for Convert Integer to the Sum of Two No-Zero Integers.

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;
        while (true) {
            int i = a;
            while (i > 0) {
                if (i % 10 != 0) i /= 10;
                else { i = -1; break; }
            }
            if (i < 0) { ++a; --b; continue; }
            
            int j = b;
            while (j > 0) {
                if (j % 10 != 0) j /= 10;
                else { j = -1; break; }
            }
            if (j < 0) { ++a; --b; continue; }
            
            return {a, b};
        }
        return {a, b};
    }
};