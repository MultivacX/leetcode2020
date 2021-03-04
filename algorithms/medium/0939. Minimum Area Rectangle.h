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


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // rect: {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
        // x1: {y1, y2, ...}
        // y1 * 40001 + y2: {x1, x2, ...}
        unordered_map<int, vector<int>> m_x;
        for (const auto& p : points) 
            m_x[p[0]].push_back(p[1]);
        unordered_map<int, vector<int>> m_y1y2;
        for (const auto& it : m_x) {
            int x = it.first;
            for (int i = 0; i + 1 < it.second.size(); ++i) {
                int y1 = it.second[i];
                for (int j = i + 1; j < it.second.size(); ++j) {
                    int y2 = it.second[j];
                    m_y1y2[min(y1, y2) * 40001 + max(y1, y2)].push_back(x);
                }
            }
        }
        
        int ans = INT_MAX;
        for (const auto& it : m_x) {
            int x1 = it.first;
            for (int i = 0; i + 1 < it.second.size(); ++i) {
                int y1 = it.second[i];
                for (int j = i + 1; j < it.second.size(); ++j) {
                    int y2 = it.second[j];
                    auto& v_x2 = m_y1y2[min(y1, y2) * 40001 + max(y1, y2)];
                    for (int x2 : v_x2) {
                        if (x1 == x2) continue;
                        ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};