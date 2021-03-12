// 70. Climbing Stairs

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.2 MB, less than 98.53% of C++ online submissions for Climbing Stairs.

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int a = 2;
        int b = 3;
        for (int i = 4; i <= n; ++i) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int s1 = 1, s2 = 2, s = 0;
        for (int i = 3; i <= n; ++i) {
            s = s1 + s2;
            s1 = s2;
            s2 = s;
        }
        return s;
    }
};