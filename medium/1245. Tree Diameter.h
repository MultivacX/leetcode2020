// 1245. Tree Diameter
// https://leetcode.com/problems/tree-diameter/

// Runtime: 136 ms, faster than 15.86% of C++ online submissions for Tree Diameter.
// Memory Usage: 31.1 MB, less than 8.50% of C++ online submissions for Tree Diameter.
    
class Solution {
    int ans = 0;
    
    int bfs(unordered_map<int, unordered_set<int>>& es, int i) {
        auto children = move(es[i]);
        es.erase(i);
        int cnt1 = 0, cnt2 = 0;
        for (int j : children) {
            if (es.count(j) == 0) 
                continue;
            es[j].erase(i);
            int c = bfs(es, j);
            if (cnt1 <= 0) cnt1 = c;
            else if (cnt2 <= 0) cnt2 = c;
            else if (c >= cnt1) {
                if (cnt1 > cnt2) cnt2 = cnt1;
                cnt1 = c;
            } else if (c >= cnt2) {
                if (cnt2 > cnt1) cnt1 = cnt2;
                cnt2 = c;
            }
        }
        if (cnt1 > 0 && cnt2 > 0) {
            ans = max(ans, cnt1 + cnt2);
        } else {
            ans = max(ans, cnt1);
            ans = max(ans, cnt2);
        }
        return max(cnt1 + 1, cnt2 + 1);
    }
    
public:
    int treeDiameter(vector<vector<int>>& edges) {
        const int N = edges.size() + 1;
        unordered_map<int, unordered_set<int>> es;
        for (auto& e : edges) {
            es[e[0]].insert(e[1]);
            es[e[1]].insert(e[0]);
        }
        bfs(es, 0);
        return ans;
    }
};