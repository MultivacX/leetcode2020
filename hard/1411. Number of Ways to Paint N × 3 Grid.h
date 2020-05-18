// 1411. Number of Ways to Paint N × 3 Grid

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Ways to Paint N × 3 Grid.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Number of Ways to Paint N × 3 Grid.

// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution {
public:
    int numOfWays(int n) {
        uint64_t xyz = 6; // -> {yzx, zxy} {yxy, yzy}
        uint64_t xyx = 6; // -> {yxz, zxy} {zxz, yxy, yzy}
        for (int i = 2; i <= n; ++i) {
            uint64_t i_xyz = xyz * 2 % 1000000007 + xyx * 2 % 1000000007;
            uint64_t i_xyx = xyz * 2 % 1000000007 + xyx * 3 % 1000000007;
            xyz = i_xyz % 1000000007;
            xyx = i_xyx % 1000000007;
        }
        return (xyz + xyx) % 1000000007;
    }
};