// 762. Prime Number of Set Bits in Binary Representation
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

// Runtime: 32 ms, faster than 46.75% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
// Memory Usage: 6.4 MB, less than 34.66% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
    
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        static const unordered_set<int> primes{
            2, 3, 5, 7, 11, 13, 17, 19
        };
        int cnt = 0;
        for (int i = L; i <= R; ++i) 
            if (primes.count(__builtin_popcount(i)))
                ++cnt;
        return cnt;
    }
};