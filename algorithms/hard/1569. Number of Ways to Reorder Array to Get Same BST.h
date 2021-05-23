// 1569. Number of Ways to Reorder Array to Get Same BST
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

// Runtime: 140 ms, faster than 64.58% of C++ online submissions for Number of Ways to Reorder Array to Get Same BST.
// Memory Usage: 61 MB, less than 48.96% of C++ online submissions for Number of Ways to Reorder Array to Get Same BST.
    
class Solution {
    const int64_t MOD = 1000000007;
    
    int64_t comb(int N, int K) {
        int64_t nx = 1;
        // i!
        for (int64_t i = 2; i <= N; ++i) nx = nx * i % MOD;

        const int M = max(K, N - K) + 1;
        vector<int64_t> inv(M, 0), inv_kx(M, 0);
        inv[0] = inv_kx[0] = inv[1] = inv_kx[1] = 1;
        // https://cp-algorithms.com/algebra/module-inverse.html
        // 1 / i!
        for (int64_t i = 2; i < M; ++i) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
            inv_kx[i] = inv_kx[i - 1] * inv[i] % MOD;
            // cout << i << ":" << inv_kx[i] << "  ";
        }
        
        // N! / (K! * (N - K)!)
        return nx * inv_kx[K] % MOD * inv_kx[N - K] % MOD;
    }
    
    int64_t ways(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        
        vector<int> l, r;
        for (int i = 1; i < nums.size(); ++i)
            nums[i] < nums[0] ? l.push_back(nums[i]) : r.push_back(nums[i]);
        int64_t c = comb(l.size() + r.size(), l.size()), lw = ways(l), rw = ways(r);
        return c * lw % MOD * rw % MOD;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        // root = nums[0]
        // l[i] < root; r[i] > root
        // comb(l.size + r.size, l.size) * numOfWays(l) * numOfWays(r) - 1
        
        return ways(nums) - 1; 
    }
};