// 849. Maximize Distance to Closest Person
// https://leetcode.com/problems/maximize-distance-to-closest-person/

// Runtime: 24 ms, faster than 89.30% of C++ online submissions for Maximize Distance to Closest Person.
// Memory Usage: 17.4 MB, less than 32.34% of C++ online submissions for Maximize Distance to Closest Person.

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        int person = -1;
        int dist = 0;
        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                if (person == -1 && i > 0) dist = i;
                else dist = max(dist, (i - person) / 2);
                person = i;
            } else if (i + 1 == N) {
                dist = max(dist, i - person);
            }
        }
        return dist;
    }
};