// 1488. Avoid Flood in The City
// https://leetcode.com/problems/avoid-flood-in-the-city/

// Runtime: 536 ms, faster than 97.05% of C++ online submissions for Avoid Flood in The City.
// Memory Usage: 107.9 MB, less than 5.35% of C++ online submissions for Avoid Flood in The City.

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> fullLakes;
        set<int> canDryIndexes;
        const int N = rains.size();
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            if (rains[i] > 0) {
                if (fullLakes.count(rains[i])) {
                    auto it = canDryIndexes.upper_bound(fullLakes[rains[i]]);
                    if (it == canDryIndexes.end()) return {};
                    
                    ans[i] = -1;
                    fullLakes[rains[i]] = i;
                    ans[*it] = rains[i];
                    canDryIndexes.erase(it);
                } else {
                    ans[i] = -1;
                    fullLakes.emplace(rains[i], i);
                }
            } else {
                ans[i] = -2;
                if (fullLakes.size() > canDryIndexes.size())
                    canDryIndexes.insert(i);
            }
        }
        for (int& i : ans) if (i == -2) i = 1;
        return ans;
    }
};