// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/

// Runtime: 20 ms, faster than 24.22% of C++ online submissions for N-Queens II.
// Memory Usage: 8.1 MB, less than 20.61% of C++ online submissions for N-Queens II.

class Solution {
    unordered_set<int> R;
    unordered_set<int> C;
    unordered_set<int> D1;
    unordered_set<int> D2;
    int N;
    int ans;
    
    bool check(int r, int c, int& d1, int& d2) {
        if (R.count(r)) return false;
        if (C.count(c)) return false;
        
        // r - k, c - k
        int k1 = min(r - 1, c - 1);
        d1 = (r - k1) * N + c - k1;
        // printf("[%d, %d] -> [%d, %d]\n", r, c, r - k1, c - k1);
        if (D1.count(d1)) return false;
        
        // r + k, c - k
        int k2 = min(N - r, c - 1);
        d2 = (r + k2) * N + c - k2;
        // printf("[%d, %d] -> [%d, %d]\n", r, c, r + k2, c - k2);
        if (D2.count(d2)) return false;
        
        R.insert(r);
        C.insert(c);
        D1.insert(d1);
        D2.insert(d2);
        
        return true;
    }
    
    void count(int r) {
        if (r > N) {
            ++ans;
            return;
        }
        for (int c = 1; c <= N; ++c) {
            int d1, d2;
            if (!check(r, c, d1, d2)) continue;
            count(r + 1);
            R.erase(r);
            C.erase(c);
            D1.erase(d1);
            D2.erase(d2);
        }
    }
    
public:
    int totalNQueens(int n) {
        N = n;
        ans = 0;
        int d1, d2;
        for (int c = 1; c <= n / 2; ++c) {
            check(1, c, d1, d2);
            count(2);
            R.clear();
            C.clear();
            D1.clear();
            D2.clear();
        }
        ans *= 2;
        if (n & 1) {
            check(1, n / 2 + 1, d1, d2);
            count(2);
        }
        return ans;
    }
};
