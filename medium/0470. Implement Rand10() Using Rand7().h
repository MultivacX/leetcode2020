// 470. Implement Rand10() Using Rand7()

// Runtime: 68 ms, faster than 77.65% of C++ online submissions for Implement Rand10() Using Rand7().
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Implement Rand10() Using Rand7().

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int v = 49;
        // v = [0, 48]
        while (v >= 40) v = rand() % 7 + rand() % 7 * 7;
        // for (int i = 0; i < 40; ++i) cout << ((i >> 2) + 1) << " ";
        return (v >> 2) + 1;
    }
};