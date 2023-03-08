class Solution {
public:
    long long coloredCells(int n) {
        // 1: 1,                     0
        // 2: 1 + 3,                 1
        // 3: 1 + 3 + 5,             1 + 3
        // n: 1 + ... , 2 * n - 1,   1 + ... , 2 * (n - 1) - 1

        long long k = n;
        return k * k + (k - 1) * (k - 1);
    }
};