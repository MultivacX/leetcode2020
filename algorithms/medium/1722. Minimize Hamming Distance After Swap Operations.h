// 1722. Minimize Hamming Distance After Swap Operations
// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

// Runtime: 352 ms, faster than 92.16% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
// Memory Usage: 143.9 MB, less than 62.55% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
    
class Solution {
    int find(vector<int>& parents, vector<int>& weights, int i) {
        if (parents[i] == -1) { 
            parents[i] = i;
            weights[i] = 1;
        } else {
            while (i != parents[i]) 
                i = parents[i];        
        }
        return i;
    }
    
    void connect(vector<int>& parents, vector<int>& weights, int i, int j) {
        int ri = find(parents, weights, i);
        int rj = find(parents, weights, j);
        if (ri == rj) return;
        
        if (weights[ri] >= weights[rj]) {
            parents[rj] = ri;
            weights[ri] += weights[rj];
        } else {
            parents[ri] = rj;
            weights[rj] += weights[ri];
        }
    }
    
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int N = source.size();
        vector<int> parents(N, -1);
        vector<int> weights(N, 0);
        for (const auto& v : allowedSwaps) 
            connect(parents, weights, v[0], v[1]);
        
        // root_idx, {val, cnt}
        unordered_map<int, unordered_map<int, int>> m;
        for (int i = 0; i < N; ++i) {
            int ri = find(parents, weights, i);
            if (ri < 0) continue;
            ++m[ri][source[i]];
        }
        
        int ans = N;
        for (int i = 0; i < N; ++i) {
            int ri = find(parents, weights, i);
            if (ri < 0) {
                if (source[i] == target[i])
                    --ans;
            } else {
                auto& vals = m[ri];
                if (vals.count(target[i])) {
                    --ans;
                    if (--vals[target[i]] == 0)
                        vals.erase(target[i]);
                }
            }
        }
        return ans;
    }
};