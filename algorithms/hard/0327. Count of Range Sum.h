// 327. Count of Range Sum

// Runtime: 112 ms, faster than 5.57% of C++ online submissions for Count of Range Sum.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Count of Range Sum.

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();
        if (n <= 0 || lower > upper) return 0;
        
        // sums[i] = sum(0, i)
        vector<int64_t> sums(n, 0);
        sums[0] = nums[0];
        vector<int64_t> s(n, 0); // optim : int64_t* s = new int[n]; int64_t* t = new int[n];
        s[0] = sums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] += sums[i - 1] + nums[i];
            s[i] = sums[i];
        }
        sort(s.begin(), s.end());
        
        int64_t lower64 = lower;
        int64_t upper64 = upper;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto l = lower_bound(s.begin(), s.begin() + n - i, lower64); // l >= lower64
            auto u = upper_bound(s.begin(), s.begin() + n - i, upper64); // u > upper64
            ans += u - l;
            // printf("[%lld, %lld] : %lld\n", lower64, upper64, sums[i]);
            
            lower64 += nums[i];
            upper64 += nums[i];
            auto it = lower_bound(s.begin(), s.begin() + n - i, sums[i]);
            s.erase(it); // optim : memcpy s(it, n - i) to t, then memcpy t to s[it, n - i)
        }
        return ans;
    }
};