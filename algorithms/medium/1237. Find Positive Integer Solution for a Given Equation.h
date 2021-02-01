// 1237. Find Positive Integer Solution for a Given Equation
// https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

// Runtime: 4 ms, faster than 46.40% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
// Memory Usage: 6.2 MB, less than 82.90% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
    
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; ++x) {
            int l = 1, r = 1001;
            while (l < r) {
                int y = l + (r - l) / 2;
                int v = customfunction.f(x, y);
                if (v == z) {
                    ans.push_back({x, y});
                    break;
                }
                if (v > z) r = y;
                else l = y + 1;
            }
        }
        return ans;
    }
};