// 1599. Maximum Profit of Operating a Centennial Wheel
// https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/

// Runtime: 384 ms, faster than 17.19% of C++ online submissions for Maximum Profit of Operating a Centennial Wheel.
// Memory Usage: 81.7 MB, less than 60.08% of C++ online submissions for Maximum Profit of Operating a Centennial Wheel.

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int gondolas[4] = {0, 0, 0, 0};
        int idx = 0; // S:0 W:1 N:2 E:3
        int wait = 0, board = 0, rotate = 0, total = 0;
        int profit = 0;
        int ans = 0;
        
        auto op = [&](){
            // back to ground
            board -= gondolas[idx];
            
            // on board
            int c = min(4, wait);
            gondolas[idx] = c;
            board += c;
            wait -= c;
            total += c;
            
            // rotate
            idx = (idx + 1) % 4;
            ++rotate;
            
            int cur_profit = total * boardingCost - rotate * runningCost;
            if (profit < cur_profit) {
                profit = cur_profit;
                ans = rotate;
            }
            // printf("wait:%d, total:%d, rotate:%d, cur_profit:%d\n", wait, total, rotate, cur_profit);
        };
        
        for (int i = 0; i < customers.size(); ++i) {
            wait += customers[i];
            op();
        }
        while (wait > 0) op();
        return profit > 0 ? ans : -1;
    }
};