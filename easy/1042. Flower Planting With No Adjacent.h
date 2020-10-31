// 1042. Flower Planting With No Adjacent
// https://leetcode.com/problems/flower-planting-with-no-adjacent/

// Runtime: 240 ms, faster than 68.46% of C++ online submissions for Flower Planting With No Adjacent.
// Memory Usage: 46.3 MB, less than 5.31% of C++ online submissions for Flower Planting With No Adjacent.
    
class Solution {
    void planting(vector<int>& ans, vector<vector<int>>& to, int i) {
        if (ans[i] > 0) return;
        
        int used = 0;
        for (int j : to[i]) used |= (1 << ans[j]);
        for (int b = 1; b <= 4 && ans[i] == 0; ++b) 
            if ((used & (1 << b)) == 0) ans[i] = b;
        for (int j : to[i]) planting(ans, to, j);
    }
    
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, 0);
        vector<vector<int>> to(n);
        for (auto p : paths) {
            to[p[0] - 1].push_back(p[1] - 1);
            to[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < n; ++i) 
            planting(ans, to, i);
        return ans;
    }
};