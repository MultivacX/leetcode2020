// 939. Minimum Area Rectangle

// Runtime: 1020 ms, faster than 31.80% of C++ online submissions for Minimum Area Rectangle.
// Memory Usage: 15.7 MB, less than 100.00% of C++ online submissions for Minimum Area Rectangle.

// Time Complexity: O(N*N).
// Space Complexity: O(N).

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // {x, {y}}
        unordered_map<int, unordered_set<int>> m;
        for (auto& p : points) m[p[0]].insert(p[1]);
        
        const int N = points.size();
        uint64_t ans = 1 + (uint64_t)INT_MAX;
        for (int i = 0; i < N - 1; ++i) {
            auto& A = points[i];
            for (int j = i + 1; j < N; ++j) {
                auto& B = points[j];
                if (A[0] == B[0] || A[1] == B[1]) continue;
                
                int cx = A[0], cy = B[1];
                if (m[cx].count(cy) == 0) continue;
                int dx = B[0], dy = A[1];
                if (m[dx].count(dy) == 0) continue;
                
                uint64_t area = abs(A[0] - B[0]) * abs(A[1] - B[1]);
                ans = min(ans, area);
            }
        }
        return ans > (uint64_t)INT_MAX ? 0 : ans;
    }
};