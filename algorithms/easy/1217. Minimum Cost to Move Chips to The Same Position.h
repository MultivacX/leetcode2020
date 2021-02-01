// 1217. Minimum Cost to Move Chips to The Same Position
// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

// Runtime: 4 ms, faster than 52.74% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
// Memory Usage: 7.6 MB, less than 78.32% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
    
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int i : position) i % 2 ? ++odd : ++even;
        return min(odd, even);
    }
};