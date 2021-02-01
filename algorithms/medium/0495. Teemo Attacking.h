// 495. Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/

// Runtime: 80 ms, faster than 40.70% of C++ online submissions for Teemo Attacking.
// Memory Usage: 26.2 MB, less than 100.00% of C++ online submissions for Teemo Attacking.

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        const int N = timeSeries.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i + 1 == N) ans += duration;
            else ans += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        return ans;
    }
};