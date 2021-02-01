// 1052. Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/

// Runtime: 68 ms, faster than 66.89% of C++ online submissions for Grumpy Bookstore Owner.
// Memory Usage: 32.9 MB, less than 10.12% of C++ online submissions for Grumpy Bookstore Owner.

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int N = customers.size();
        vector<int> prefix(N, 0);
        prefix[0] = customers[0] * (1 - grumpy[0]);
        for (int i = 1; i < N; ++i) prefix[i] += prefix[i - 1] + customers[i] * (1 - grumpy[i]);
        
        int x = 0;
        for (int i = 0; i < X; ++i) x += customers[i];
        int ans = x + prefix[N - 1] - prefix[X - 1];
        for (int i = X; i < N; ++i) {
            x = x + customers[i] - customers[i - X];
            ans = max(ans, prefix[i - X] + x + prefix[N - 1] - prefix[i]);
        }
        return ans;
    }
};