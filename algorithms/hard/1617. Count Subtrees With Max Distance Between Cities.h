// 1617. Count Subtrees With Max Distance Between Cities
// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/

// Runtime: 148 ms, faster than 34.41% of C++ online submissions for Count Subtrees With Max Distance Between Cities.
// Memory Usage: 7.2 MB, less than 73.12% of C++ online submissions for Count Subtrees With Max Distance Between Cities.
    
class Solution {
    void count(int n, int state, const vector<vector<int>>& dists, vector<int>& ans) {
        int cities = 0, edges = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & state) == 0) continue;
            ++cities;
            for (int j = i + 1; j < n; ++j) {
                if (((1 << j) & state) == 0) continue;
                if (dists[i][j] == 1) ++edges;
                d = max(d, dists[i][j]);
            }
        }
        // cout << bitset<4>(state) << " " << d << endl;
        if (cities == edges + 1 && d > 0) ++ans[d - 1];
    }
    
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> dists(n, vector<int>(n, n * 2));
        for (const auto& e : edges) 
            dists[e[0] - 1][e[1] - 1] = dists[e[1] - 1][e[0] - 1] = 1;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j)
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
        
        vector<int> ans(n - 1);
        for (int state = 0; state < (1 << n); ++state) 
            count(n, state, dists, ans);
        return ans;
    }
};