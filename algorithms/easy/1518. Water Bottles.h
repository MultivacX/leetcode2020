// 1518. Water Bottles
// https://leetcode.com/problems/water-bottles/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Water Bottles.
// Memory Usage: 6.2 MB, less than 76.20% of C++ online submissions for Water Bottles.
    
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while (numBottles >= numExchange) {
            int n = numBottles / numExchange;
            int drink = n * numExchange;
            numBottles = n + numBottles - drink;
            ans += drink;
        }
        return ans + numBottles;
    }
};