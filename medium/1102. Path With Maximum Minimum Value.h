// 1102. Path With Maximum Minimum Value
// https://leetcode.com/problems/path-with-maximum-minimum-value/

// Runtime: 900 ms, faster than 46.41% of C++ online submissions for Path With Maximum Minimum Value.
// Memory Usage: 31 MB, less than 81.22% of C++ online submissions for Path With Maximum Minimum Value.
    
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        const int m = A.size();
        const int n = A[0].size();
        priority_queue<array<int, 3>> q;
        q.push({A[0][0], 0, 0});
        A[0][0] = -1;
        int ans = INT_MAX;
        while (!q.empty()) {
            auto [v, i, j] = q.top();
            q.pop();
            ans = min(ans, v);
            if (i + 1 == m && j + 1 == n)
                return ans;
            
            static const vector<vector<int>> directions{
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
            };
            for (const auto& d : directions) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || A[ni][nj] < 0)
                    continue;
                q.push({A[ni][nj], ni, nj});
                A[ni][nj] = -1;
            }
        }
        return -1;
    }
};