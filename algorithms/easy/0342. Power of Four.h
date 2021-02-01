// 342. Power of Four

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Four.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Power of Four.

// Time Complexity: O(1).
// Space Complexity: O(1).

class Solution {
public:
    bool isPowerOfFour(int num) {
        static const unordered_set<int> s{1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
        return s.count(num);
    }
};