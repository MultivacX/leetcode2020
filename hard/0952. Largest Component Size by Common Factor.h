// 952. Largest Component Size by Common Factor

// Time Limit Exceeded
// 78 / 100 test cases passed.
class Solution {
    void pollards_rho(int n, unordered_set<int>& factors) {
        for (int i = 2; i < n; ++i) {
            while (i != n) {
                if (n % i == 0) {
                    factors.insert(i);
                    n /= i;
                } else break;
            }
        }
        if (n != 1) factors.insert(n);
    }
    
public:
    int largestComponentSize(vector<int>& A) {
        const int N = A.size();
        vector<unordered_set<int>> factors(N);
        unordered_map<int, unordered_set<int>> f2i;
        for (int i = 0; i < N; ++i) {
            pollards_rho(A[i], factors[i]);
            for (int f : factors[i]) f2i[f].insert(i);
        }
        
        int ans = 0;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;
            
            int cnt = 1;
            unordered_set<int> visited_factors;
            unordered_set<int> is{i};
            unordered_set<int> fs;
            while (!is.empty()) {
                fs.clear();
                for (int j : is) {
                    if (visited[j]) continue;
                    visited[j] = true;
                    for (int f : factors[j]) {
                        if (visited_factors.count(f)) continue;
                        fs.insert(f);
                    }
                }
                
                is.clear();
                for (int f : fs) {
                    if (visited_factors.count(f)) continue;
                    visited_factors.insert(f);
                    for (int j : f2i[f]) {
                        if (visited[j]) continue;
                        is.insert(j);
                    }
                }
                
                cnt += is.size();
            }
            
            ans = max(ans, cnt);
        }
        return ans;
    }
};