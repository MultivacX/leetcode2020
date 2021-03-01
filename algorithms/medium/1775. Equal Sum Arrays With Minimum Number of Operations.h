// 1775. Equal Sum Arrays With Minimum Number of Operations
// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

// Runtime: 148 ms, faster than 16.67% of C++ online submissions for Equal Sum Arrays With Minimum Number of Operations.
// Memory Usage: 113.7 MB, less than 33.33% of C++ online submissions for Equal Sum Arrays With Minimum Number of Operations.
    
class Solution {
    int opt(const vector<int>& m, int sum, int target) {
        int ans = 0;
        for (int val = 1; val <= 5 && sum < target; ++val) {
            int cnt = m[val];
            if (cnt == 0) continue;
            int t = target - sum;
            int v = 6 - val;
            int c = min(cnt, t / v + (t % v == 0 ? 0 : 1));
            ans += c;
            sum += c * v;
            if (sum > target) sum = target;
        }
        for (int val = 6; val >= 2 && sum > target; --val) {
            int cnt = m[val];
            if (cnt == 0) continue;
            int t = sum - target;
            int v = val - 1;
            int c = min(cnt, t / v + (t % v == 0 ? 0 : 1));
            ans += c;
            sum -= c * v;
            if (sum < target) sum = target;
        }
        return ans;
    }
    
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        // [m, 6m] [n, 6n]
        if (6 * m < n || 6 * n < m) return -1;
        
        vector<int> m1(7, 0); 
        int sum1 = 0;
        for (int i : nums1) {
            ++m1[i];
            sum1 += i;
        }
        
        vector<int> m2(7, 0); 
        int sum2 = 0;
        for (int i : nums2) {
            ++m2[i];
            sum2 += i;
        }
        
        int l = max(m, n), r = 6 * min(m, n) + 1;
        int ans = m + n;
        for (int t = l; t < r; ++t) {
            ans = min(ans, opt(m1, sum1, t) + opt(m2, sum2, t));
        }
        /*while (l < r) {
            int sum = l + (r - l) / 2;   
        }*/
        return ans;
    }
};