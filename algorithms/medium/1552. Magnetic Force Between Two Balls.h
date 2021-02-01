// 1552. Magnetic Force Between Two Balls
// https://leetcode.com/problems/magnetic-force-between-two-balls/

// Runtime: 420 ms, faster than 87.32% of C++ online submissions for Magnetic Force Between Two Balls.
// Memory Usage: 58.3 MB, less than 7.18% of C++ online submissions for Magnetic Force Between Two Balls.

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        const int N = position.size();
        sort(begin(position), end(position));
        int minForce = 1;
        int maxForce = 1 + position[N - 1] - position[0];
        int ans = 0;
        while (minForce < maxForce) {
            int midForce = minForce + (maxForce - minForce) / 2;
            
            int balls = 1;
            for (int i = 1, j = 0; i < N; ++i) {
                if (position[i] - position[j] < midForce)
                    continue;
                ++balls;
                j = i;
            }
            
            // midForce is greater
            if (balls < m) {
                maxForce = midForce;
            } else {
                minForce = midForce + 1;
                ans = max(ans, midForce);
            }
        }
        return ans;
    }
};