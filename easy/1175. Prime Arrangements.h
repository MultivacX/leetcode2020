// 1175. Prime Arrangements
// https://leetcode.com/problems/prime-arrangements/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Prime Arrangements.
// Memory Usage: 6.1 MB, less than 15.61% of C++ online submissions for Prime Arrangements.

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> notPrimes(n + 1, false);
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (notPrimes[i]) continue;
            ++cnt;
            for (int j = i + i; j <= n; j += i) 
                notPrimes[j] = true;
        }
        // for (int i = 2; i <= n; ++i) if (!notPrimes[i]) cout << i << " "; cout << endl;
        int64_t ans = 1;
        // P(cnt, cnt) * P(n - cnt, n - cnt)
        for (int64_t i = cnt; i >= 2; --i)
            ans = ans * i % 1000000007;
        for (int64_t i = n - cnt; i >= 2; --i)
            ans = ans * i % 1000000007;
        return ans;
    }
};