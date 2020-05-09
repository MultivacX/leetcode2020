// 983. Minimum Cost For Tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> passes(366, vector<int>(3, 0));
        vector<vector<int>> dp(366, vector<int>(3, 0));
        for (int day = 1, i = 0; day <= 365 && i < days.size(); ++day) {
            passes[day][0] = 0; // passes[day - 1][0] > 1 ? passes[day - 1][0] - 1 : 0;
            passes[day][1] = passes[day - 1][1] > 1 ? passes[day - 1][1] - 1 : 0;
            passes[day][2] = passes[day - 1][2] > 1 ? passes[day - 1][2] - 1 : 0;
            
            bool day_01_pass = passes[day][0] == 0;
            bool day_07_pass = passes[day][1] == 0;
            bool day_30_pass = passes[day][2] == 0;
            
            if (day == days[i]) {
                /*if (day_01_pass)*/ {
                    int min_cost_before = dp[day - 1][0];
                    if (day_07_pass) min_cost_before = min(min_cost_before, dp[day - 1][1]);
                    if (day_30_pass) min_cost_before = min(min_cost_before, dp[day - 1][2]);
                    passes[day][0] = 1;
                    dp[day][0] = min_cost_before + costs[0];
                } /*else {
                    dp[day][0] = dp[day - 1][0];
                }*/
                
                if (day_07_pass) {
                    int min_cost_before = min(dp[day - 1][0], dp[day - 1][1]);
                    if (day_30_pass) min_cost_before = min(min_cost_before, dp[day - 1][2]);
                    passes[day][1] = 7;
                    dp[day][1] = min_cost_before + costs[1];
                } else {
                    dp[day][1] = dp[day - 1][1];
                }
                
                if (day_30_pass) {
                    int min_cost_before = min(dp[day - 1][0], dp[day - 1][2]);
                    if (day_07_pass) min_cost_before = min(min_cost_before, dp[day - 1][1]);
                    passes[day][2] = 30;
                    dp[day][2] = min_cost_before + costs[2];
                } else {
                    dp[day][2] = dp[day - 1][2];
                }
                
                ++i;
            } else {
                dp[day][0] = dp[day - 1][0];
                dp[day][1] = dp[day - 1][1];
                dp[day][2] = dp[day - 1][2];
            }
        }
        
        for (int i = 0; i < 3; ++i) { for (int day : days) printf("[%d]%2d:%3d ", day, passes[day][i], dp[day][i]); cout << endl; }
        
        return min(dp[days.back()][0], min(dp[days.back()][1], dp[days.back()][2]));
    }
};