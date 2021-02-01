// 1665. Minimum Initial Energy to Finish Tasks
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

// Runtime: 468 ms, faster than 86.60% of C++ online submissions for Minimum Initial Energy to Finish Tasks.
// Memory Usage: 93.2 MB, less than 93.78% of C++ online submissions for Minimum Initial Energy to Finish Tasks.
    
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](const vector<int>& l, const vector<int>& r){
            return l[1] - l[0] > r[1] - r[0];
        });
        int ans = tasks[0][1];
        int left = tasks[0][1] - tasks[0][0];
        for (int i = 1; i < tasks.size(); ++i) {
            if (left >= tasks[i][1]) {
                left -= tasks[i][0];
            } else {
                ans += tasks[i][1] - left;
                left = tasks[i][1] - tasks[i][0];
            }
        }
        return ans;
    }
};