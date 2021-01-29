// 1402. Reducing Dishes
// https://leetcode.com/problems/reducing-dishes/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reducing Dishes.
// Memory Usage: 7.9 MB, less than 94.61% of C++ online submissions for Reducing Dishes.
    
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // sum[i-1...i+k-1] = s[i-1] + s[i] + s[i+1] + ... + s[i+k-2] + s[i+k-1]
        // val[k] =                s[i] * 1 + s[i+1] * 2 + ... + s[i+k-2] * (k-1) + s[i+k-1] * k
        // val[k+1] = s[i-1] * 1 + s[i] * 2 + s[i+1] * 3 + ... + s[i+k-2] * k + s[i+k-1] * (k+1)
        // val[k+1] = val[k] + sum[i-1...i+k-1]
        
        sort(begin(satisfaction), end(satisfaction));
        const int N = satisfaction.size();
        int ans = 0;
        int val = 0, sum = 0;
        for (int i = N - 1; i >= 0; --i) {
            val += satisfaction[i];
            val += sum;
            if (ans < val) ans = val;
            sum += satisfaction[i];
        }
        return ans;
    }
};