// 1046. Last Stone Weight

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Last Stone Weight.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        
        priority_queue<int> q;
        for (int i : stones) q.push(i);
        while (q.size() >= 2) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (y == x) continue;
            q.push(y - x);
        }
        return q.empty() ? 0 : q.top();
    }
};