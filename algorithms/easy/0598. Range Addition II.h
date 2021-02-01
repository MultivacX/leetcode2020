// 598. Range Addition II
// https://leetcode.com/problems/range-addition-ii/

// Runtime: 20 ms, faster than 74.29% of C++ online submissions for Range Addition II.
// Memory Usage: 11.4 MB, less than 38.82% of C++ online submissions for Range Addition II.

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // int val = 0; // M[0][0]
        int cnt = m * n;
        int i = INT_MAX;
        int j = INT_MAX;
        for (const auto& op : ops) {
            i = min(i, op[0]);
            j = min(j, op[1]);
            cnt = i * j;
            // ++val;
        }
        return cnt;
    }
};