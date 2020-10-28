// 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/

// Runtime: 680 ms, faster than 39.92% of C++ online submissions for Path With Minimum Effort.
// Memory Usage: 25.1 MB, less than 5.01% of C++ online submissions for Path With Minimum Effort.

class Solution { 
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int M = heights.size();
        const int N = heights[0].size();
        
        vector<vector<int>> efforts(M, vector<int>(N, INT_MAX));
        
        auto cmp = [](array<int, 3>& left, array<int, 3>& right) { return left[2] > right[2]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> q(cmp);
        q.push({0, 0, 0});        
        
        while (!q.empty()) {
            int i = q.top()[0];
            int j = q.top()[1];
            int e = q.top()[2];
            q.pop();
            // cout << i << ", " << j << ": " << e << endl;
            if (i == M - 1 && j == N - 1) return e;
            
            if (efforts[i][j] <= e) continue; 
            efforts[i][j] = e;
            
            static const int D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int k = 0; k < 4; ++k) {
                int ii = i + D[k][0];
                int jj = j + D[k][1];
                if ((ii == 0 && jj == 0) || ii < 0 || ii >= M || jj < 0 || jj >= N) continue;
                int curE = max(e, abs(heights[ii][jj] - heights[i][j]));
                // cout << "  " << ii << ", " << jj << ": " << curE << endl;
                q.push({ii, jj, curE});
            }
        }
        return 0;
    }
};