// 1103. Distribute Candies to People
// https://leetcode.com/problems/distribute-candies-to-people/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Distribute Candies to People.
// Memory Usage: 6.9 MB, less than 38.20% of C++ online submissions for Distribute Candies to People.
    
class Solution {
public:
    vector<int> distributeCandies(int candies, int n/*num_people*/) {
        // 0*n+1,    0*n+i,   0*n+n
        // 1*n+1,    1*n+i,   1*n+n
        //
        // r*n+1,    r*n+i,   r*n+n
        
        vector<int> ans(n, 0);
        int sum1 = (1 + n) * n / 2;
        if (candies <= sum1) {
            for (int i = 0; i < n && candies > 0; ++i) {
                ans[i] = min(i + 1, candies);
                candies -= ans[i];
            }
        } else {
            // sum = sum1 * (r + 1) + (0 + r) * (r + 1) / 2 * n * n
            // a*r^2 + b*r + c <= 0
            double a = n * n * 0.5;
            double b = a + sum1;
            double c = sum1 - candies;
            int r = (sqrt(b * b - 4 * a * c) - b) / (2 * a);
            
            for (int i = 0; i < n && candies > 0; ++i) {
                ans[i] = (i + 1) * (r + 1) + (0 + r) * (r + 1) / 2 * n;
                candies -= ans[i];
            }
            for (int i = 0; i < n && candies > 0; ++i) {
                int k = min((r + 1) * n + (i + 1), candies);
                ans[i] += k;
                candies -= k;
            }
        }
        return ans;
    }
};