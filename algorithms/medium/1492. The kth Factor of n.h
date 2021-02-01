// 1492. The kth Factor of n
// https://leetcode.com/problems/the-kth-factor-of-n/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for The kth Factor of n.
// Memory Usage: 6.1 MB, less than 33.33% of C++ online submissions for The kth Factor of n.

class Solution {
public:
    int kthFactor(int n, int k) {
        if (k == 1) return 1;
        
        vector<int> L{1};
        vector<int> R{n};
        for (int i = 2; i < n; ++i) {
            int j = n / i;
            if (i * j != n) continue;
            if (i > j) break;
            
            L.push_back(i);
            if (L.size() >= k) return L[k - 1];
            if (i == j) break;
            R.push_back(j);
        }
        
        if (L.size() + R.size() < k) return -1;
        k -= L.size();
        return R[R.size() - k];
    }
};