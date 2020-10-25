// 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/

// 8 / 74 test cases passed.
// Status: Time Limit Exceeded
class Solution {
    int M;
    int N;
    int ans = 1000000;
    
    void travel(vector<vector<int>>& heights, int i, int j, int pre_h, int max_e) {
        if (i < 0 || i >= M || j < 0 || j >= N || heights[i][j] == 0) return;
        
        int effort = abs(heights[i][j] - pre_h);
        if (effort >= ans) return;

        max_e = max(max_e, effort);
        // printf("[%d][%d] : %d %d\n", i, j, effort, max_e);
        if (i == M - 1 && j == N - 1) {
            ans = min(ans, max_e);
            return;
        }
        
        pre_h = heights[i][j];
        heights[i][j] = 0;
        
        travel(heights, i, j + 1, pre_h, max_e);
        travel(heights, i + 1, j, pre_h, max_e);
        travel(heights, i, j - 1, pre_h, max_e);
        travel(heights, i - 1, j, pre_h, max_e);
        
        heights[i][j] = pre_h;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();
        travel(heights, 0, 0, heights[0][0], 0);
        return ans;
    }
};