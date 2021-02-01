// 1184. Distance Between Bus Stops
// https://leetcode.com/problems/distance-between-bus-stops/

// Runtime: 4 ms, faster than 97.79% of C++ online submissions for Distance Between Bus Stops.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Distance Between Bus Stops.

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        int ans = 0;
        if (start > destination) swap(start, destination);
        for (int i = 0; i < distance.size(); ++i) {
            sum += distance[i];
            if (start <= i && i < destination) 
                ans += distance[i];
        }
        return min(sum - ans, ans);
    }
};