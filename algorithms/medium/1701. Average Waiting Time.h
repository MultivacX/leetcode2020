// 1701. Average Waiting Time
// https://leetcode.com/problems/average-waiting-time/

// Runtime: 384 ms, faster than 95.04% of C++ online submissions for Average Waiting Time.
// Memory Usage: 73.1 MB, less than 82.57% of C++ online submissions for Average Waiting Time.
    
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime = 0;
        int cur_time = 0;
        for (const auto& c : customers) {
            if (cur_time < c[0]) cur_time = c[0];
            totalTime += cur_time - c[0] + c[1];
            cur_time += c[1];
        }
        return totalTime / customers.size();
    }
};