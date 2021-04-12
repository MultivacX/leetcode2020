// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Runtime: 56 ms, faster than 20.00% of C++ online submissions for Find the Winner of the Circular Game.
// Memory Usage: 24.3 MB, less than 40.00% of C++ online submissions for Find the Winner of the Circular Game.
    
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        while (q.size() != 1) {
            int j = 1;
            while (j++ < k) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};