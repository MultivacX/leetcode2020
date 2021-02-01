// 823. Binary Trees With Factors

// Runtime: 156 ms, faster than 16.67% of C++ online submissions for Binary Trees With Factors.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Binary Trees With Factors.

// Time Complexity: O(size(A)*size(A)).
// Space Complexity: O(size(A)).

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        map<int, uint64_t> M;
        for (int a : A) M.emplace(a, 1);
        uint64_t ans = 0;
        for (auto& it : M)
            ans = (ans + build(it.first, M)) % 1000000007;
        return ans;
    }
    
    uint64_t build(int a, map<int, uint64_t>& M) {
        const int end = a >> 1;
        for (auto& it : M) {
            int l = it.first;
            if (l >= a || l > end) break;
            if (a % l) continue;
            int r = a / l;
            auto r_it = M.find(r);
            if (r_it == M.end()) continue;
            
            M[a] = (M[a] + it.second * r_it->second) % 1000000007;
        }
        return M[a];
    }
};