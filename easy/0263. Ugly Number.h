// 263. Ugly Number

// Runtime: 4 ms, faster than 57.55% of C++ online submissions for Ugly Number.
// Memory Usage: 8.2 MB, less than 40.00% of C++ online submissions for Ugly Number.

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};