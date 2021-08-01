// 1952. Three Divisors
// https://leetcode.com/problems/three-divisors/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Three Divisors.
// Memory Usage: 5.8 MB, less than 88.89% of C++ online submissions for Three Divisors.
    
class Solution {
public:
    bool isThree(int n) {
        int k = 1;
        for (int i = 2; i <= n; ++i)
            if (n % i == 0)
                ++k;
        return k == 3;
    }
};