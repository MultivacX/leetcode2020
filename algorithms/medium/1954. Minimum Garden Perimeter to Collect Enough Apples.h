// 1954. Minimum Garden Perimeter to Collect Enough Apples
// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Minimum Garden Perimeter to Collect Enough Apples.
    
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        // 12 * x * x
        long long apples = 0, x = 0;
        while (apples < neededApples) {
            ++x;
            apples += 12 * x * x;
        }
        return x * 8;
    }
};