// 2087. Minimum Cost Homecoming of a Robot in a Grid
// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

// Runtime: 500 ms, faster than 24.74% of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
// Memory Usage: 149.7 MB, less than 93.81% of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
    
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0;
        
        if (startPos[0] < homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; ++i)
                res += rowCosts[i];
        } else {
            for (int i = startPos[0] - 1; i >= homePos[0]; --i)
                res += rowCosts[i];
        }
        
        if (startPos[1] < homePos[1]) {
            for (int i = startPos[1] + 1; i <= homePos[1]; ++i)
                res += colCosts[i];
        } else {
            for (int i = startPos[1] - 1; i >= homePos[1]; --i)
                res += colCosts[i];
        }
        
        return res;
    }
};