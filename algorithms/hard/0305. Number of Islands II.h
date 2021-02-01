// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/

// Runtime: 2128 ms, faster than 5.54% of C++ online submissions for Number of Islands II.
// Memory Usage: 48 MB, less than 27.93% of C++ online submissions for Number of Islands II.
    
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        static const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int N = positions.size();
        // pi * n + pj, parent_idx
        unordered_map<int, int> parents;
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            int key = positions[i][0] * n + positions[i][1];
            if (parents.count(key)) {
                ans[i] = ans[i - 1];
                continue;
            }
            
            unordered_set<int> pre_idx;
            for (const auto& d : directions) {
                int ni = positions[i][0] + d[0];
                int nj = positions[i][1] + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                
                int nk = ni * n + nj;
                if (parents.count(nk) == 0) continue;
                
                pre_idx.insert(parents[nk]);
            }
            
            int pre_cnt = i > 0 ? ans[i - 1] : 0;
            int idx_cnt = pre_idx.size();
            ans[i] = pre_cnt + 1 - idx_cnt;
            int parent = i;
            
            if (idx_cnt == 1) {
                parent = *pre_idx.begin();
            } else if (idx_cnt > 1) {
                parent = *pre_idx.begin();
                for (auto& it : parents)
                    if (pre_idx.count(it.second))
                        it.second = parent;
            }
            parents.emplace(key, parent);
        }
        return ans;
    }
};

// TLE
// 159 / 162 test cases passed.
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        static const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int N = positions.size();
        // pi * n + pj, parent_idx
        unordered_map<int64_t, int> parents;
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            int64_t key = (int64_t)positions[i][0] * n + (int64_t)positions[i][1];
            if (parents.count(key)) {
                ans[i] = ans[i - 1];
                continue;
            }
            
            unordered_set<int> pre_idx;
            for (const auto& d : directions) {
                int ni = positions[i][0] + d[0];
                int nj = positions[i][1] + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                
                int nk = (int64_t)ni * n + (int64_t)nj;
                if (parents.count(nk) == 0) continue;
                
                pre_idx.insert(parents[nk]);
            }
            
            int pre_cnt = i > 0 ? ans[i - 1] : 0;
            ans[i] = pre_cnt + 1 - pre_idx.size();
            
            for (auto& it : parents) {
                if (pre_idx.count(it.second) == 0)
                    continue;
                it.second = i;
            }
            
            parents.emplace(key, i);
        }
        return ans;
    }
};