// 1697. Checking Existence of Edge Length Limited Paths
// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

// Runtime: 528 ms, faster than 85.97% of C++ online submissions for Checking Existence of Edge Length Limited Paths.
// Memory Usage: 110.2 MB, less than 65.97% of C++ online submissions for Checking Existence of Edge Length Limited Paths.
    
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(begin(edgeList), end(edgeList), [](const vector<int>& l, const vector<int>& r){
            return l[2] < r[2];
        });
        vector<int> parents(n);
        vector<int> wieghts(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            wieghts[i] = 1;
        }
        
        auto find = [&](int u){
            while (u != parents[u])
                u = parents[u];
            return u;
        };
        
        const int m = queries.size();
        for (int i = 0; i < m; ++i)
            queries[i].push_back(i);
        sort(begin(queries), end(queries), [](const vector<int>& l, const vector<int>& r){
            return l[2] < r[2];
        });
        
        vector<bool> ans(m);
        int i = 0;
        for (const auto& query : queries) {
            int p = query[0], q = query[1], limit = query[2], j = query[3];
            while (i < edgeList.size() && edgeList[i][2] < limit) {
                int u = edgeList[i][0], v = edgeList[i][1];
                int pu = find(u), pv = find(v);
                if (pu != pv) {
                    if (wieghts[pu] >= wieghts[pv]) {
                        wieghts[pu] += wieghts[pv];
                        parents[pv] = parents[pu];
                    } else {
                        wieghts[pv] += wieghts[pu];
                        parents[pu] = parents[pv];
                    }
                }
                ++i;
            }
            ans[j] = find(p) == find(q);
        }
        return ans;
    }
};