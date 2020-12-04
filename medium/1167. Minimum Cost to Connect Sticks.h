// 1167. Minimum Cost to Connect Sticks
// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

// Runtime: 308 ms, faster than 90.05% of C++ online submissions for Minimum Cost to Connect Sticks.
// Memory Usage: 24.5 MB, less than 32.55% of C++ online submissions for Minimum Cost to Connect Sticks.
    
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int s : sticks) q.push(s);
        int ans = 0;
        while (q.size() > 1) {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            q.push(a + b);
            ans += a + b;
        }
        return ans;
    }
};