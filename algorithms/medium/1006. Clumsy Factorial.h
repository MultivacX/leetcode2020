// 1006. Clumsy Factorial
// https://leetcode.com/problems/clumsy-factorial/

// Runtime: 4 ms, faster than 25.94% of C++ online submissions for Clumsy Factorial.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Clumsy Factorial.

class Solution {
public:
    int clumsy(int N) {
        // static const vector<char> opts{'*', '/', '+', '-'};
        
        vector<int> ans;
        int val = N;
        int opt = 0;
        for (int i = N - 1; i > 0; --i, ++opt) {
            opt %= 4;
            if (opt == 0) {
                val = val * i;
            } else if (opt == 1) {
                val = val / i;
            } else if (opt == 2) {
                val = val + i;
            } else {
                ans.push_back(val);
                val = -i;
            }
        }
        return accumulate(begin(ans), end(ans), val);
    }
};