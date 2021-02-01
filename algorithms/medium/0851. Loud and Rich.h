// 851. Loud and Rich

// Runtime: 476 ms, faster than 6.25% of C++ online submissions for Loud and Rich.
// Memory Usage: 42.6 MB, less than 100.00% of C++ online submissions for Loud and Rich.

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int N = quiet.size();
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) 
            ans[i] = i;
        vector<vector<int>> nodes(N, vector<int>());
        vector<vector<int>> poorer(N, vector<int>());
        for (auto& r : richer) {
            // money(r[0]) > money(r[1])
            poorer[r[0]].push_back(r[1]);
            nodes[r[1]].push_back(r[0]);
        }
        
        unordered_set<int> s;
        for (int i = 0; i < N; ++i) {
            // money(i) > money(nodes[i][j])
            if (nodes[i].empty()) {
                s.insert(i);
            }
        }
        while (!s.empty()) {
            unordered_set<int> t;
            for (int i : s) {
                // printf("%d ", i);
                // money(i) > money(nodes[i][j])
                for (int j : poorer[i]) {
                    if (quiet[ans[j]] > quiet[ans[i]]) 
                        ans[j] = ans[i];
                    t.insert(j);
                }
            }
            // cout << endl;
            swap(s, t);
        }
        return ans;
    }
};