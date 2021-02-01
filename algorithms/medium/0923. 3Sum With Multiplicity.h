// 923. 3Sum With Multiplicity

// Runtime: 16 ms, faster than 72.81% of C++ online submissions for 3Sum With Multiplicity.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for 3Sum With Multiplicity.

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, uint64_t> m;
        for (int a : A) ++m[a];
        
        // i < j < k
        // sort(A) : A[i] <= A[j] <= A[k]
        // 1. A[i] == A[j] == A[k]
        // 2. A[i] == A[j] <  A[k]
        // 3. A[i] <  A[j] == A[k]
        // 4. A[i] <  A[j] <  A[k]
        
        uint64_t ans = 0;
        for (auto i = m.begin(); i != m.end(); ++i) {
            int ai = i->first;
            if (ai > target) break;
            for (auto j = i; j != m.end() && i->first + j->first <= target; ++j) {
                int aj = j->first;
                if (ai + aj > target) break;
                int ak = target - ai - aj;
                if (ak < aj) break;
                auto k = m.find(ak);
                if (k == m.end()) continue;
                
                if (ai == aj && aj == ak) {
                    if (i->second >= 3) ans = (ans + i->second * (i->second - 1) * (i->second - 2) / 6) % 1000000007;
                } else if (ai == aj && aj < ak) {
                    if (i->second >= 2) ans = (ans + i->second * (i->second - 1) / 2 * k->second) % 1000000007;
                } else if (ai < aj && aj == ak) {
                    if (j->second >= 2) ans = (ans + j->second * (j->second - 1) / 2 * i->second) % 1000000007;
                } else {
                    ans = (ans + i->second * j->second * k->second) % 1000000007;
                }
            }
        }
        return ans;
    }
};