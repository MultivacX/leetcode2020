// 1818. Minimum Absolute Sum Difference
// https://leetcode.com/problems/minimum-absolute-sum-difference/

// Runtime: 1076 ms, faster than 33.33% of C++ online submissions for Minimum Absolute Sum Difference.
// Memory Usage: 152.9 MB, less than 33.33% of C++ online submissions for Minimum Absolute Sum Difference.
    
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int64_t ans = 0;
        for (int i = 0; i < nums1.size(); ++i)
            ans += abs(nums1[i] - nums2[i]);
        if (ans == 0) return 0;
        
        auto cmp = [](const auto& l, const auto& r){
            return abs(l[0] - l[1]) < abs(r[0] - r[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < nums1.size(); ++i)
            q.push({nums1[i], nums2[i]});
        
        sort(begin(nums1), end(nums1));
        
        int64_t sum = ans;
        while (!q.empty()) {
            int n1 = q.top()[0];
            int n2 = q.top()[1];
            q.pop();
            
            // *(it - 1) < n2 <= *it
            auto it = lower_bound(begin(nums1), end(nums1), n2);
            if (it != end(nums1)) ans = min(ans, sum - abs(n1 - n2) + abs(*it - n2));
            if (it != begin(nums1)) ans = min(ans, sum - abs(n1 - n2) + abs(*(--it) - n2));
        }
        return ans % 1000000007;
    }
};