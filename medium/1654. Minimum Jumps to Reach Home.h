// 1654. Minimum Jumps to Reach Home
// https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> useless(forbidden.begin(), forbidden.end());
        // {x, f or b, steps}
        unordered_map<int, int> visited;
        int steps = 0;
        unordered_set<int> s;
        s.insert(0);
        while (!s.empty()) {
            ++steps;
            
            unordered_set<int> t;
            for (int cur_x : s) {
                if (!visited.count(cur_x) || !(visited[cur_x] & 1)) {
                    // forward
                    int f = cur_x + a;
                    if (f == x) return steps;
                    if (!(f > x && f - b > x)) t.insert(f);
                    visited[cur_x] |= 1;
                }
                
                if (!visited.count(cur_x) || !(visited[cur_x] & 2)) {
                    // backward
                    if (it.second & 2) continue;
                    int b = x0 - b;
                    if (b <= 0) continue;
                }
            }
        }
    }
};