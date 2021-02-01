// 1304. Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find N Unique Integers Sum up to Zero.
// Memory Usage: 7.1 MB, less than 87.60% of C++ online submissions for Find N Unique Integers Sum up to Zero.
    
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for (int i = 1, j = 0; i <= n / 2; ++i)
            ans[j++] = -i, ans[j++] = i;
        return ans;
    }
};