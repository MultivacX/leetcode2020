// 829. Consecutive Numbers Sum
// https://leetcode.com/problems/consecutive-numbers-sum/

// Runtime: 4 ms, faster than 83.85% of C++ online submissions for Consecutive Numbers Sum.
// Memory Usage: 6.2 MB, less than 5.08% of C++ online submissions for Consecutive Numbers Sum.

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        // sum[x, x + i)
        // sum(x, x + i - 1) = i * x + (i - 1) * i / 2
        int ans = 1;
        for (int i = 2; (i - 1) * i < N * 2; ++i) {
            int ix = N - (i - 1) * i / 2;
            int x = ix / i;
            if (i * x != ix) continue;
            ++ans;
            // for (int ii = 0; ii < i; ++ii) cout << x + ii << " + "; cout << endl;
        }
        return ans;
    }
};