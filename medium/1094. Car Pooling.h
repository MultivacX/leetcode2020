// 1094. Car Pooling
// https://leetcode.com/problems/car-pooling/

// Runtime: 20 ms, faster than 75.24% of C++ online submissions for Car Pooling.
// Memory Usage: 10.2 MB, less than 25.38% of C++ online submissions for Car Pooling.

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> count;
        for (const auto& t : trips) {
            count[t[1]] += t[0];
            count[t[2]] -= t[0];
        }
        int pre = 0;
        for (auto it : count) {
            int c = it.second + pre;
            // cout << "location:" << it.first << ", passengers:" << c << endl;
            if (c > capacity) return false;
            pre = c;
        }
        return true;
    }
};