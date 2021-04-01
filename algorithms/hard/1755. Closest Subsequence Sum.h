// 1755. Closest Subsequence Sum
// https://leetcode.com/problems/closest-subsequence-sum/

// Runtime: 676 ms, faster than 69.41% of C++ online submissions for Closest Subsequence Sum.
// Memory Usage: 61.5 MB, less than 60.26% of C++ online submissions for Closest Subsequence Sum.
    
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if (goal == 0) return 0;
        const int n = nums.size();
        
        vector<int> sums0{0}, sums1{0};
        for (int i = 0; i < n / 2; ++i) {
            const int m = sums0.size();
            for (int j = 0; j < m; ++j)
                sums0.push_back(sums0[j] + nums[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            const int m = sums1.size();
            for (int j = 0; j < m; ++j)
                sums1.push_back(sums1[j] + nums[i]);
        }
        sort(begin(sums1), end(sums1));
        
        int ans = INT_MAX;
        for (int i = 0; i < sums0.size(); ++i) {
            // min(|sums0[i] + sums1[j] - goal|)
            int v = sums0[i] - goal;
            auto it = lower_bound(begin(sums1), end(sums1), -v);
            if (it == begin(sums1)) {
                ans = min(ans, abs(sums0[i] + (*it) - goal));
            } else if (it == end(sums1)) {
                ans = min(ans, abs(sums0[i] + (*(--it)) - goal));
            } else {
                ans = min(ans, abs(sums0[i] + (*it) - goal));
                ans = min(ans, abs(sums0[i] + (*(--it)) - goal));
            }
        }
        return ans;
    }
};