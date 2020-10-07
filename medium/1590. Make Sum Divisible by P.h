// 1590. Make Sum Divisible by P
// https://leetcode.com/problems/make-sum-divisible-by-p/

// Runtime: 580 ms, faster than 20.50% of C++ online submissions for Make Sum Divisible by P.
// Memory Usage: 98.2 MB, less than 5.04% of C++ online submissions for Make Sum Divisible by P.

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int N = nums.size();
        
        // {remainder, indexes of [0, i]}
        unordered_map<int, vector<int>> prefixes;
        // {remainder, indexes of [j, N)}
        // unordered_map<int, vector<int>> suffixes;
        
        int ans = N + 1;
        
        vector<int64_t> prefix_sums;
        int64_t prefix = 0;
        for (int i = 0; i < N; ++i) {
            prefix += nums[i];
            prefix_sums.push_back(prefix);
            int remainder = prefix % p;
            prefixes[remainder].push_back(i);
            
            if (remainder == 0 && prefix >= p) {
                ans = min(ans, N - i - 1);
            }
        }
        
        if (prefix < p) return -1;
        if (ans == 0) return ans;
        
        int64_t suffix = 0;
        for (int j = N - 1; j > 0; --j) {
            suffix += nums[j];
            
            int pr = prefix % p;
            if (prefixes.count(pr) && !prefixes[pr].empty()) {
                prefixes[pr].pop_back();
            }
            prefix -= suffix;
            
            int sr = suffix % p;
            pr = p - sr;
            if (prefixes.count(pr)) {
                while (!prefixes[pr].empty() && prefixes[pr].back() >= j) {
                    prefixes[pr].pop_back();
                }
                if (prefixes[pr].empty()) {
                    prefixes.erase(pr);
                } else if (prefix_sums[prefixes[pr].back()] + suffix >= p) {
                    ans = min(ans, j - prefixes[pr].back() - 1);
                }
            }
            
            if (sr == 0 && suffix >= p) {
                ans = min(ans, j);
            }
        }
        
        if (ans > N) return -1;
        return ans;
    }
};
