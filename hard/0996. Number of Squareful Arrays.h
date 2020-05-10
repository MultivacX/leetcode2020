// 996. Number of Squareful Arrays

// Runtime: 4 ms, faster than 45.10% of C++ online submissions for Number of Squareful Arrays.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Number of Squareful Arrays.

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        const int N = A.size();
        if (N == 1) {
            int ps = sqrt(A[0]);
            if (ps * ps != A[0]) return 0;
            return 1;
        }
        sort(begin(A), end(A));
        
        // {i, j}, A[i] + A[j] is a perfect square
        unordered_map<int, vector<int>> B;
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int ps = sqrt(A[i] + A[j]);
                if (ps * ps != A[i] + A[j]) continue;
                B[i].emplace_back(j);
                B[j].emplace_back(i);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i - 1] == A[i]) continue;
            // C.emplace_back(A[i]);
            count(A, B, i, 1 << i, 1, ans);
            // C.pop_back();
        }
        return ans;
    }
    
    // vector<int> C;
    
    void count(const vector<int>& A, const unordered_map<int, vector<int>>& B, int idx, int idx_used, int cnt, int& ans) {
        if (A.size() == cnt) {
            // for (int c : C) cout << c << " "; cout << endl;
            ++ans;
            return;
        }
        
        if (B.count(idx) == 0) return;
        
        const auto& V = B.at(idx);
        unordered_set<int> val_used;
        for (int k = 0; k < V.size(); ++k) {
            int j = V[k];
            if (idx_used & (1 << j)) continue;
            if (val_used.count(A[j])) continue;
            
            val_used.emplace(A[j]);
            // C.emplace_back(A[j]);
            count(A, B, j, idx_used | (1 << j), cnt + 1, ans);   
            // C.pop_back();
        }
    }
};