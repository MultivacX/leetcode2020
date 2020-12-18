// 573. Squirrel Simulation
// https://leetcode.com/problems/squirrel-simulation/

// Runtime: 44 ms, faster than 83.87% of C++ online submissions for Squirrel Simulation.
// Memory Usage: 21.7 MB, less than 38.71% of C++ online submissions for Squirrel Simulation.
    
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        const int N = nuts.size();
        // vector<int> nuts2tree(N);
        // vector<int> nuts2squirrel(N);
        vector<int> v(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            // nuts2tree[i] = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
            // nuts2squirrel[i] = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
            // sum += nuts2tree[i];
            int t = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
            int s = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
            v[i] = s - t;
            sum += t;
        }
        // ans = min(ans, (sum - nuts2tree[i]) * 2 + (nuts2squirrel[i] + nuts2tree[i]));
        int ans = INT_MAX;
        sum *= 2;
        for (int i = 0; i < N; ++i) 
            ans = min(ans, sum + v[i]);
        return ans;
    }
};